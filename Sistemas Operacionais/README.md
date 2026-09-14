# Sistemas Operacionais (Operating Systems)

C programs for Linux that explore memory, processes, threads and system calls.

| Class | Files | Description |
| --- | --- | --- |
| [Aula 01](Aula%2001) | `p1.c` – `p5.c`, `pilha.c` | Memory layout: heap exhaustion, the address of code/data/stack, out-of-bounds writes and a stack buffer overflow that overwrites a return address. **These demos rely on undefined behavior on purpose** to show what the OS and the compiler do. |
| [Aula 02](Aula%2002) | `main.c` | Process creation with `fork()` and a zombie process. |
| [Aula 03](Aula%2003) | `main_fib.c`, `main_thread.c` | Recursive Fibonacci timed sequentially and with two POSIX threads computing `fib(n-1)` and `fib(n-2)`. |
| [Aula 04](Aula%2004) | `primos.c`, `shm.c`, `threads-1.c`, `threads-2.c` | Parallel prime counting, a race condition on shared memory, creating/joining threads and passing arguments and return values. |
| [Aula 05](Aula%2005) | `main.c`, `include/`, `source/` | First stage of a process-scheduling simulator: reads the processes from standard input and lists them. |
| [Aula 11](Aula%2011) | `sort.c` | Simplified `sort` utility: reads files with the `open`/`read`/`close` system calls and prints their lines in lexicographic order. |

## Building

```bash
gcc -Wall -pthread "Aula 04/primos.c" -o primos
gcc -Wall -Iinclude main.c source/*.c -o escalonador   # inside Aula 05
```
