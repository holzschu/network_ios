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
            url: "https://github.com/yury/ios_system/releases/download/v2.7.0/ios_system.xcframework.zip",
            checksum: "394d519bf69f2a28da063a2fb9a163f623133d5769c114fb0bd6406b554e0473"
        )
    ]
)
