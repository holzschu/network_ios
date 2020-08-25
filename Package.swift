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
            checksum: "ce46512e22db14cde4467402f3f2ef1053d610657eafe436fda2ea7dfede7d93"
        )
    ]
)
