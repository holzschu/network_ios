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
            checksum: "f71aab4be3534fb60cd0d18b43fccd8290da06083030d071c297f380ee300336"
        )
    ]
)
