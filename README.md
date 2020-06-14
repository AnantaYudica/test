# test  

## Status:
| Version|   |
:---:|---
![GitHub release (latest SemVer)](https://img.shields.io/github/v/release/AnantaYudica/test?color=green&label=last-release&sort=semver) |  ![Visual Studio Build Test](https://github.com/AnantaYudica/test/workflows/Visual%20Studio%20Build%20Test/badge.svg?branch=master&event=push) ![Unix Build Test](https://github.com/AnantaYudica/test/workflows/Unix%20Build%20Test/badge.svg?branch=master&event=push) ![MSYS Build Test](https://github.com/AnantaYudica/test/workflows/MSYS%20Build%20Test/badge.svg?branch=master&event=push)

 - Development
   | Branch |   |
   :----:|---
   Beta | ![Visual Studio Build Test](https://github.com/AnantaYudica/test/workflows/Visual%20Studio%20Build%20Test/badge.svg?branch=beta&event=push)  ![Unix Build Test](https://github.com/AnantaYudica/test/workflows/Unix%20Build%20Test/badge.svg?branch=beta&event=push)  ![MSYS Build Test](https://github.com/AnantaYudica/test/workflows/MSYS%20Build%20Test/badge.svg?branch=beta&event=push)

## Definition
   - Directories
     | Directory | Description |
     :-----|:-----
     /cmake | CMake source project directory
     /external | Submodules directory
     /include | Header files directory
     /test | Test main sources directory

## Prerequisites
- Dependencies:
  | Name | Tag | Repository |
  -------|-----|------------
  build-utils | v0.1.4-cmake | https://github.com/AnantaYudica/build_utils.git
- Standard Language: __c++11__
- __Git__: minimum version=2.14
- __CMake__: minimum version=3.0.2
- Windows Compiler Support:
  - Visual Studio
  - MSYS-GCC
  - MinGw-GCC
  - Cygwin-GCC

 - Linux Compiler Support:
   - GCC
   - LLVM-Clang
## Build
   1. __Clone Project__
      ````
      git clone --recurse-submodules https://github.com/AnantaYudica/test.git test
      ````
      git clone documentation (https://git-scm.com/docs/git-clone)
   1. __Change to Project Directory__
      ````
      cd ./test
      ````
   1. __Checkout Specific Tag__ [Optional] (Tag Example: v0.1)
      ````
      git fetch --tags
      git checkout v0.1
      ````
      git fetch documentation (https://git-scm.com/docs/git-fetch), git checkout documentation (https://git-scm.com/docs/git-checkout)
   1. __Create build Directory in Project Directory__ (Folder Example: .build)
      ````
      mkdir .build
      ````
   1. __Change to Build Directory__
      ````
      cd ./.build
      ````
   1. __Generate Project__
      - __Cmake__
        - Visual Studio (Example: Visual Studio 16)
          ````
          cmake ../cmake -G "Visual Studio 16 2019"
          ````
        - Windows-MSYS
          ````
          cmake ../cmake -G "MSYS Makefiles"
          ````
        - Windows-MinGw
          ````
          cmake ../cmake -G "MinGW Makefiles"
          ````
        - Linux-GCC or Windows-Cygwin
          ````
          cmake ../cmake -G "Unix Makefiles"
          ````
        - Linux-Clang (Example: Clang version 9)
          ````
          export CC=/usr/bin/clang-9
          export CXX=/usr/bin/clang++-9
          cmake ../cmake -G "Unix Makefiles"
          ````
        CMake documentation (https://cmake.org/cmake/help/latest/manual/cmake.1.html), CMake generator documentation (https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html)

   1. Build Project
      - Windows-Visual Studio
        - Build with Visual Studio
          1. open `test.sln`
          1. build project ALL_BUILD 
        - Build with msbuild
          ````
          msbuild ALL_BUILD.vcxproj
          ````

      - Windows-MinGw
        ````
        mingw32-make build
        ````
      - Linux, Windows-MSYS or Windows-Cygwin
        ````
        make build
        ````
   1. Testing
      - Windows-Visual Studio
        - Build project RUN_TESTS for Testing in Visual Studio
        - Testing with msbuild
          ````
          msbuild RUN_TESTS.vcxproj
          ````

      - Windows-MinGw
        ````
        mingw32-make test
        ````
      - Linux, Windows-MSYS or Windows-Cygwin
        ````
        make test
        ````

## Authors
   * [Ananta Yudica](https://github.com/AnantaYudica)
## License
   This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/AnantaYudica/test/blob/master/LICENSE) file for details
