# Installation Guide — OpenMP with GCC on Windows

This guide explains how to install **MSYS2, GCC, and OpenMP** required to run the Parallel Computing practical programs.

## 1. Install MSYS2

Download and install MSYS2 from:

[MSYS2 Official Website](https://www.msys2.org/?utm_source=chatgpt.com)

After installation, open:

**MSYS2 UCRT64**

> Use the **UCRT64** terminal for all the commands below.

---

## 2. Update MSYS2

Run:

```bash
pacman -Syu
```

If it asks you to close the terminal, close it and open **MSYS2 UCRT64** again.

Then run:

```bash
pacman -Su
```

---

## 3. Install GCC

In the **MSYS2 UCRT64** terminal, run:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

Press **Y** when asked for confirmation.

Check that GCC is installed:

```bash
gcc --version
```

You should see the installed GCC version.

---

## 4. OpenMP Support

OpenMP is included with the GCC installation, so **no separate OpenMP installation is required**.

To compile an OpenMP program, use the `-fopenmp` option:

```bash
gcc -fopenmp program.c -o program
```

---

## 5. Test OpenMP

Create a file named:

```text
test.c
```

Add:

```c
#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello from thread %d\n", omp_get_thread_num());
    }

    return 0;
}
```

Compile:

```bash
gcc -fopenmp test.c -o test
```

Run:

```bash
./test
```

If OpenMP is installed correctly, you should see output from multiple threads, such as:

```text
Hello from thread 0
Hello from thread 1
Hello from thread 2
Hello from thread 3
```

The exact number of threads depends on your computer.

## Installation Complete

You now have everything required to run the Parallel Computing OpenMP programs:

- **MSYS2 UCRT64** — development environment
- **GCC** — C compiler
- **OpenMP** — parallel programming support included with GCC

For all four practical programs, compile using:

```bash
gcc -fopenmp program.c -o program
```