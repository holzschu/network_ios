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
            checksum: "faa7fcc0b6f6a3a2c127d3d6f843b43a9dbffe5461c6703b31587eb51c00500b"
        ),

        .target(
            name: "build",
            dependencies: ["FMake"]
        ),
    ]
)
