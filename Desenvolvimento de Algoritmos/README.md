# Desenvolvimento de Algoritmos (Algorithm Development)

C exercises from the second programming course, organized by class. Every file compiles as C99 with `-Wall -Wextra` without warnings.

| Class | Topics |
| --- | --- |
| [Aula 01](Aula%2001) | First C program: input/output, conditionals and loops. |
| [Aula 02](Aula%2002) | Averages of input sequences, dynamic allocation of vectors, energy bill using pointers (`ex_02`). |
| [Aula 03](Aula%2003) | Functions: declaration, return values and pass-by-reference with pointers. |
| [Aula 04](Aula%2004) | Arrays: mean, linear search, bubble sort and common elements (`ex_04`). |
| [Aula 05](Aula%2005) | Sorting with a swap function and intersection of sorted arrays. |
| [Aula 06](Aula%2006) | `malloc`/`free`, array reversal, trapezoidal-rule integration, standard deviation. |
| [Aula 07](Aula%2007) | Standard deviation of *n* numbers with dynamic allocation (two versions). |
| [Aula 08](Aula%2008) | Dynamically allocated matrices: creation, filling, printing, multiplication and freeing. |
| [Aula 09](Aula%2009) | Patterns in square matrices; point closest to the origin. |
| [Aula 10](Aula%2010) | Strings as `'\0'`-terminated `char` arrays. |
| [Aula 12](Aula%2012) | Recursion: factorial and countdown. |
| [Aula 13](Aula%2013) | Recursion exercises: arithmetic series, digit count, product, power, GCD, power tower. |
| [Aula 14](Aula%2014) | Structs passed by value and by reference. |
| [Aula 15](Aula%2015) | Tower of Hanoi, Fibonacci, line intersection and triangle classification. |
| [Aula 16](Aula%2016) | Cash book with nested structs: add, remove and print entries. |
| [Aula 17](Aula%2017) | Complex-number calculator using structs. |
| [Aula 18](Aula%2018) | Reading and writing text files. |
| [Aula 19](Aula%2019) | Polygon perimeter with vertices and result stored in files. |
| [Aula 21](Aula%2021/projetoJanela) | GUI with the IUP library: a window with text boxes and a button that opens a second window. |
| [Aula 22](Aula%2022) | Function pointers: generic sorting of structs with a configurable criterion. |
| [Aula 23](Aula%2023) | Function pointers as parameters: search with configurable comparison rule and factor. |

## Building

```bash
gcc -std=c99 -Wall -Wextra "Aula 15/main.c" -o aula15 -lm
```

`Aula 21` is a CLion/CMake project based on the example provided in class; it links against the prebuilt Windows IUP binaries in `projetoJanela/iup` (third-party library from Tecgraf/PUC-Rio).
