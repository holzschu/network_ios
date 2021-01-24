// use it from root folder:
// `swift run --package-path xcfs build`

import Foundation
import FMake 

OutputLevel.default = .error

enum Config {
    static let iOSSystemVersion = "2.6"
    static let iOSSystemRoot    = "https://github.com/holzschu"

    static var iOSSystemErrorHURL: String {
        "\(iOSSystemRoot)/ios_system/releases/download/\(iOSSystemVersion)/ios_error.h"
    }
}

extension Platform {
  var excludedArchs: [Platform.Arch] {
      switch self {
          case .iPhoneSimulator: return [.arm64] // TODO: add arm64 simulator
          default: return []
      }
  }
}

try download(url: Config.iOSSystemErrorHURL)

// TODO: We can add more platforms here
let platforms: [Platform] = [.iPhoneOS, .iPhoneSimulator]

let schemes = [ "network_ios" ]

var checksums: [(file: String, value: String)] = []

for scheme in schemes {
    try xcxcf(
        dirPath: ".build",
        project: "network_ios",
        scheme: scheme,
        platforms: platforms.map { ($0, excludedArchs: $0.excludedArchs) },
        enableBitCode: false
    )

    try cd(".build") {
        let zip = "\(scheme).xcframework.zip"
        try sh("zip -r \(zip) \(scheme).xcframework")
        let chksum = try sha(path: zip)
        checksums.append((file: zip, value: chksum))
    }
}

var releaseNotes =
"""
Release notes:

    | File                            | SHA 256                                             |
    | ------------------------------- |:---------------------------------------------------:|
\(checksums.map {
    "    | \($0.file) | \($0.value) |"
}.joined(separator: "\n"))

"""

try write(content: releaseNotes, atPath: ".build/release.md")

