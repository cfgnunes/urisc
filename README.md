# uRisc emulator

Emulador de processador uRISC.

## Getting Started

### Prerequisites

This section assumes Ubuntu 16.04 (also tested on Ubuntu 22.04), but the procedure is similar for other Linux distributions. The prerequisites to build the source is to install the following packages:

```sh
sudo apt -y install build-essential cmake
```

### Build the project

To build the project, use:

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

## Built With

- [GCC](https://gcc.gnu.org/) - The GNU Compiler Collection
- [CMake](https://cmake.org/) - Build, test and package software
