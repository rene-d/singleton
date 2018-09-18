#! /bin/bash

set -e

ctest --build-and-test . build --build-generator "Unix Makefiles" --build-options -DCMAKE_BUILD_TYPE=Release

CC=/usr/local/bin/gcc-8 CXX=/usr/local/bin/g++-8 \
ctest --build-and-test . build-gcc --build-generator "Unix Makefiles" --build-options -DCMAKE_BUILD_TYPE=Release

strip build*/z*
pr -m -t <(echo CLANG; stat -f "%10z %N" build/z*) <(echo GCC; stat -f "%10z %N" build-gcc/z*)
