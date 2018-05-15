#!/bin/bash

IOS_SYSTEM_VER="2.0"
LIBSSH2_VER="1.0"

HHROOT="https://github.com/holzschu"

(cd "${BASH_SOURCE%/*}/Frameworks"
# ios_system
echo "Downloading fat frameworks:"
curl -OL $HHROOT/libssh2-for-iOS/releases/download/v$LIBSSH2_VER/release.tar.gz
( tar -xzf release.tar.gz && rm release.tar.gz ) || { echo "libssh2 failed to download"; exit 1; }
)

echo "Downloading header file:"
curl -OL $HHROOT/ios_system/releases/download/v$IOS_SYSTEM_VER/ios_error.h 




