// swift-tools-version:5.3
import PackageDescription

_ = Package(
    name: "deps",
    platforms: [.macOS("11")],
    dependencies: [
        .package(url: "https://github.com/yury/FMake", from: "0.0.16")
    ],
    
    targets: [
        .binaryTarget(
            name: "ios_system",
            url: "https://github.com/holzschu/ios_system/releases/download/v2.7.0/ios_system.xcframework.zip",
            checksum: "e98c075c088f916649426720afa50df03904aa36d321fe072c9bd6ccbc12806c"
        ),
        .target(
            name: "build",
            dependencies: ["FMake"]
        ),
    ]
)
