#!/usr/bin/env sh

set -e

SOURCE_DIR="$(pwd)"
TARGET_DIR="${SOURCE_DIR}/target"

build() {
    mkdir -p $TARGET_DIR
    cd $TARGET_DIR
    cmake $SOURCE_DIR
    make
}

(build)
