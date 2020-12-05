#!/bin/bash

IOS_SYSTEM_VER="2.6"

HHROOT="https://github.com/holzschu"

echo "Downloading header file:"
curl -OL $HHROOT/ios_system/releases/download/$IOS_SYSTEM_VER/ios_error.h 

# First, creat all frameworks for both architectures: 
xcodebuild -project network_ios.xcodeproj -alltargets -sdk iphoneos -configuration Release -quiet
xcodebuild -project network_ios.xcodeproj -alltargets -sdk iphonesimulator -arch x86_64 -configuration Release -quiet

# then, merge them into XCframeworks:
for framework in network_ios
do
   rm -rf $framework.xcframework
   xcodebuild -create-xcframework -framework build/Release-iphoneos/$framework.framework -framework build/Release-iphonesimulator/$framework.framework -output $framework.xcframework
   # while we're at it, let's compute the checksum:
   rm -f $framework.xcframework.zip
   zip -r $framework.xcframework.zip $framework.xcframework
   swift package compute-checksum $framework.xcframework.zip
done



