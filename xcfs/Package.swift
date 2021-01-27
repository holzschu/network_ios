// swift-tools-version:5.3
import PackageDescription

_ = Package(
    name: "deps",
    platforms: [.macOS("11")],
    dependencies: [
        .package(url: "https://github.com/yury/FMake", from: "0.0.15")
    ],
    
    targets: [
        .binaryTarget(
            name: "ios_system",
            url: "https://github.com/yury/ios_system/releases/download/v2.7.0/ios_system.xcframework.zip",
            checksum: "a3ec1c198b944b7d0e8932b7da447b164ae9b869c11c8f0f35cc7b5f09129fe2"
        ),

        .target(
            name: "build",
            dependencies: ["FMake"]
        ),
    ]
)