// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "network_ios",
    products: [
        .library(name: "network_ios", targets: ["network_ios"])
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(
            name: "network_ios",
            url: "https://github.com/holzschu/network_ios/releases/download/0.2/network_ios.xcframework.zip",
            checksum: "0d521e4d92a843401414cd7d22d3919a8ec38bfa340d6fdfcd56b792379364fb"
        )
    ]
)
