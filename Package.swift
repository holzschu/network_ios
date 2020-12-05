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
            checksum: "b67a5e0094610a40dea8f14511ca10aad4bd10f9c3969b8d484ea758fe37db0d"
        )
    ]
)
