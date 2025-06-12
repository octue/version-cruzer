# version-cruzer

Building semantic versioning into Strands

## Running Locally

To build the project in development mode and run the tests, make sure you have
a working C++20 compiler (either GCC or Clang will work), CMake >=3.16,
ClangFormat (only for developing the C++ components), and simply run:

```sh
make
```

## WebAssembly Bindings

To generate the WebAssembly package under `bindings/webassembly`, run:

```sh
make webassembly
```

## Python Bindings

To generate the Python modules under `bindings/python`, run:

```sh
make python
```

## Releasing

To produce a release, including pushing bindings to the corresponding package
managers, create and push a tag of the form `vX.Y.Z`. For example:

```sh
git tag --annotate v1.2.3 --message v1.2.3
```
