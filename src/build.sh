#!/bin/bash

# build.sh - Compiles the engine into a static library
# Usage: ./build.sh (produces libspinlock.a)

set -e

# Compiler and archiver settings

CXX="${CXX:-clang++}"
AR="ar"
ARFLAGS="rcs"

# Output directories
BUILD_DIR="build"
LIB_DIR="lib"
mkdir -p "$BUILD_DIR"
mkdir -p "$LIB_DIR"

# Compile unity build
echo "Compiling engine..."
$CXX -std=c++20 -O2 -c src/build.cpp -o "$BUILD_DIR/build.o"

# Create static library
echo "Creating static library..."
$AR $ARFLAGS "$LIB_DIR/libspinlock.a" "$BUILD_DIR/build.o"

echo "Complete: $LIB_DIR/libspinlock.a"
