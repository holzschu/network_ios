// From: https://github.com/gumb0/wol.cpp
/* **************************************************
 * wol.cpp - Simple Wake-On-LAN utility to wake a networked PC.
 * Usage: wol [-q] [-b <bcast>] [-p <port>] <dest>
 * Compile it with: g++ -Wall -Os -DNDEBUG -std=c++11 -o wol wol.cpp
 *
 * ************************************************** */

#include <arpa/inet.h>
#include <errno.h>
#include <getopt.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
// iOS changes:
#include "ios_error.h"

namespace
{
    class socket_handle
    {
    public:
        explicit socket_handle(int descriptor) : _descriptor(descriptor) {
            if (_descriptor < 0) {
                fprintf(thread_stderr, "Failed to open socket\n");
                pthread_exit(NULL);
                // throw std::runtime_error("Failed to open socket");
            }
        }
        socket_handle(const socket_handle&) = delete;
        socket_handle& operator=(const socket_handle&) = delete;

        int get() const {
            return _descriptor;
        }

        ~socket_handle() {
            close(_descriptor);
        }

    private:
        const int _descriptor;
    };


    void print_usage(const std::string& progname)
    {
        // std::cerr << "Usage: " << progname << " [-q] [-b <bcast>] [-p <port>] <dest>\n";
        fprintf(thread_stderr, "Usage: %s  [-q] [-b <bcast>] [-p <port>] <dest>\n", progname.c_str());
    }

    // Attempts to extract hexadecimal from ASCII string.
    unsigned get_hex_from_string(const std::string& s)
    {
        unsigned hex{0};
        
        for (size_t i = 0; i < s.length(); ++i) {
            hex <<= 4;
            if (isdigit(s[i])) {
                hex |= s[i] - '0';
            }
            else if (s[i] >= 'a' && s[i] <= 'f') {
                hex |= s[i] - 'a' + 10;
            }
            else if (s[i] >= 'A' && s[i] <= 'F') {
                hex |= s[i] - 'A' + 10;
            }
            else {
                fprintf(thread_stderr, "Failed to parse hexadecimal: %s\n", s.c_str());
                pthread_exit(NULL);
                // throw std::runtime_error("Failed to parse hexadecimal " + s);
            }
        }
        return hex;
    }

    // Extract inet address from hardware address.
    std::string get_ether(const std::string& hardware_addr)
    {
        std::string ether_addr;

        for (size_t i = 0; i < hardware_addr.length();) {
            // Parse two characters at a time.
            unsigned hex = get_hex_from_string(hardware_addr.substr(i, 2));
            i += 2;

            ether_addr += static_cast<char>(hex & 0xFF);

            // We might get a colon here, but it is not required.
            if (hardware_addr[i] == ':')
                ++i;
        }

        if (ether_addr.length() != 6) {
            fprintf(thread_stderr,  "%s not a valid ether address\n", hardware_addr.c_str());
            pthread_exit(NULL);
            // throw std::runtime_error(hardware_addr + " not a valid ether address");
        }

        return ether_addr;
    }

    // Sends Wake-On-LAN packet to given address with the given options, where the
    // address is in the form "XX:XX:XX:XX:XX:XX" (the colons are optional).
    void send_wol(const std::string& hardware_addr, unsigned port, unsigned long bcast)
    {
        // Fetch the hardware address.
        const std::string ether_addr{get_ether(hardware_addr)};

        socket_handle packet{socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)};

        // Build the message to send.
        //   (6 * 0XFF followed by 16 * destination address.)
        std::string message(6, 0xFF);
        for (size_t i = 0; i < 16; ++i) {
            message += ether_addr;
        }

        // Set socket options.
        const int optval{1};
        if (setsockopt(packet.get(), SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval)) < 0) {
            // throw std::runtime_error("Failed to set socket options");
            fprintf(thread_stderr,  "Failed to set socket options\n");
            pthread_exit(NULL);
        }

        // Set up address
        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = bcast;
        addr.sin_port = htons(port);

        // Send the packet out.
        if (sendto(packet.get(), message.c_str(), message.length(), 0,
            reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) < 0) {
            // throw std::runtime_error("Failed to send packet");
            fprintf(thread_stderr,  "Failed to send packet\n");
            pthread_exit(NULL);
        }
    }
}

int wol_main(int argc, char * const argv[])
{
    try
    {
        int c{0};
        unsigned port{60000};
        bool quiet{false};
        unsigned long bcast{0xFFFFFFFF};

        while ((c = getopt(argc, argv, "hqb:p:d:")) != -1) {
            switch (c) {
                case 'h': // help
                    print_usage(argv[0]);
                    return 1;
                case 'q': // quiet
                    quiet = true;
                    break;
                case 'b': // bcast
                    bcast = inet_addr(optarg);
                    if (bcast == INADDR_NONE) {
                        // throw std::runtime_error("Option -b requires address as argument");
                        fprintf(thread_stderr,  "Option -b requires address as argument\n");
                        pthread_exit(NULL);
                    }
                    break;
                case 'p': // port
                    port = strtol(optarg, NULL, 0);
                    if (port == 0 && errno != 0) {
                        // throw std::runtime_error("Option -p requires integer as argument.");
                        fprintf(thread_stderr,  "Option -p requires integer as argument.\n");
                        pthread_exit(NULL);
                    }
                    break;
                case '?': // unrecognized option
                    if (optopt == 'b' || optopt == 'p' || optopt == 'd') {
                        // throw std::runtime_error(std::string("Option -") + static_cast<char>(optopt) + " requires an argument");
                        fprintf(thread_stderr,  "Option -%c requires an argument.\n", c);
                        pthread_exit(NULL);
                    } else {
                        // throw std::runtime_error(std::string("Unknown option '-") + static_cast<char>(optopt) + "'");
                        fprintf(thread_stderr,  "Unknown option '-%c'\n", c);
                        pthread_exit(NULL);
                    }
                default:
                    // throw std::runtime_error("Internal error");
                    fprintf(thread_stderr,  "Internal error\n");
                    pthread_exit(NULL);
            }
        }

        // Parse any remaining arguments (not options).
        if (optind == argc - 1) {
            send_wol(argv[optind], port, bcast);
            
            if (!quiet) {
                fprintf(thread_stdout, "Packet sent to %lX '-'%s on port %d\n", bcast, argv[optind], port);
                // std::cout << "Packet sent to " << std::hex << std::uppercase << htonl(bcast) << '-' << argv[optind]
                //    << " on port " << std::dec << port << '\n';
            }
        } else {
            print_usage(argv[0]);
            return 1;
        }
    }
    catch(const std::exception& e) {
        fprintf(thread_stderr, "%s\n", e.what());
        // std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}

