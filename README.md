# uRisc emulator

Emulador de processador uRISC.

## Getting Started

### Prerequisites

This section assumes Ubuntu, but the procedure is similar for other Linux distributions. The prerequisites to build the source is to install the following packages:

```sh
sudo apt -y install build-essential cmake
```

### Build the project

To build the project, use:

```sh
cmake -Wno-deprecated -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -B build
cmake --build build --parallel
```

## Built With

- [GCC](https://gcc.gnu.org/) - The GNU Compiler Collection
- [CMake](https://cmake.org/) - Build, test and package software
