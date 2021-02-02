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
            url: "https://github.com/holzschu/ios_system/releases/download/v2.7.0/ios_system.xcframework.zip",
            checksum: "83545ba08c01d0ea813fa48133efd64f734a0c3900e8e123188e9e9d2907ca90"
        ),
        .target(
            name: "build",
            dependencies: ["FMake"]
        ),
    ]
)
