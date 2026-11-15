# uRISC emulator

uRISC stands for Ultimate Reduced Instruction Set Computer.

## Getting Started

You can use [Miniconda](https://docs.conda.io)  to install the required compiler and build tools:

```sh
conda create -y -n urisc --override-channels -c conda-forge gxx make cmake
conda activate urisc
```

To configure and build the project, run:

```sh
cmake -B build
cmake --build build --parallel
```

To run a test, use:

```sh
./build/urisc test/teste10
```

## Built With

- [GCC](https://gcc.gnu.org/) - The GNU Compiler Collection
- [CMake](https://cmake.org/) - Build, test and package software
