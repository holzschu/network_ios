// swift-tools-version:5.3
import PackageDescription

_ = Package(
    name: "xcfs",
    platforms: [.macOS("11")],
    dependencies: [
        .package(url: "https://github.com/yury/FMake", from: "0.0.16")
    ],
    
    targets: [
        .binaryTarget(
            name: "ios_system",
            url: "https://github.com/holzschu/ios_system/releases/download/v3.0.1/ios_system.xcframework.zip",
            checksum: "635fc346304416f05f94a61ded08a2a5792f5072081eca7c142834326366d4d0"
        ),
        .target(
            name: "build",
            dependencies: ["FMake"]
        ),
    ]
)
