# Programming Method C Programming

- **Name**: Omer Faruk Uyar
- **Student ID**: 20268501
- **Department**: Game Development, International Collage, Dongseo University
- **Environment**: I used GCC on Linux, no IDEs. Code is portable so it can run anywhere. You can install clang on Windows with VS backend, or with MinGW UCRT:

``` shell
winget install --exact --id MartinStorsjo.LLVM-MinGW.UCRT
```

## How to compile and run

Project uses my own build system library:

1. Compile `shuild.c` in root directory

``` shell
gcc shuild.c -o shuild.ignore
./shuild.ignore
```

2. Then you can find individual binaries for each exercise under `build/`
