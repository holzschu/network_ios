// swift-tools-version:5.3
import PackageDescription

_ = Package(
    name: "deps",
    platforms: [.macOS("11")],
    dependencies: [
        .package(url: "https://github.com/yury/FMake", from: "0.0.8")
    ],
    
    targets: [
        .binaryTarget(
            name: "ios_system",
            url: "https://github.com/holzschu/ios_system/releases/download/2.7/ios_system.xcframework.zip",
            checksum: "9f60fec58e4354fe8b9568ef1b2f252c77e1b15abc011636b81ec04b5fca8c41"
        ),

        .target(
            name: "build",
            dependencies: ["FMake"]
        ),
    ]
)