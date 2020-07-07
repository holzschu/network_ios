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
            url: "https://github.com/holzschu/network_ios/releases/download/1.0/network_ios.xcframework.zip",
            checksum: "61ff7ab2aa17dc4259bad795dc016a82c25dde13c3a0f461f408143d51463711"
        )
    ]
)
