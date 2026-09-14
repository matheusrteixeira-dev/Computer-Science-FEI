# Computer Science — Undergraduate Coursework

Exercises, labs and small projects I wrote during my B.Sc. in Computer Science at Centro Universitário FEI (Brazil).
The work is grouped by course. Most code comments and program output are in Portuguese, the language the courses were taught in.

## Courses

| Course | Topics | Languages / tools |
| --- | --- | --- |
| [Fundamentos de Algoritmos](Fundamentos%20de%20Algoritmos) (Algorithm Fundamentals) | Control flow, lists, matrices, files, dictionaries, modules, Tkinter GUIs | Python |
| [Desenvolvimento de Algoritmos](Desenvolvimento%20de%20Algoritmos) (Algorithm Development) | Pointers, dynamic memory, strings, recursion, structs, files, function pointers | C |
| [Estrutura de Dados](Estrutura%20de%20Dados) (Data Structures) | Sequential and linked lists, stacks, queues, hash table, heap, BST, AVL tree | C++ |
| [Programação Orientada a Objetos](Programa%C3%A7%C3%A3o%20Orientada%20a%20Objetos) (Object-Oriented Programming) | Classes, aggregation/composition, inheritance, interfaces, exceptions, MVC with Swing | Java |
| [Análise e Complexidade de Algoritmos](An%C3%A1lise%20e%20Complexidade%20de%20Algoritmos) (Algorithm Analysis) | Sorting algorithms (bubble, heap, merge, radix), BFS, dynamic programming (LCS, rod cutting, matrix-chain, assembly line) | Python, C++, Java |
| [Arquitetura de Computadores](Arquitetura%20de%20Computadores) (Computer Architecture) | 8051 addressing modes, arithmetic, loops, timers, interrupts, 7-segment display | 8051 Assembly |
| [Cálculo Numérico](C%C3%A1lculo%20Num%C3%A9rico) (Numerical Methods) | Linear systems, root finding, least squares, interpolation, numerical integration, ODEs, FFT | Python (NumPy, SciPy, SymPy) |
| [Probabilidade e Estatística](Probabilidade%20e%20Estatistica) (Probability and Statistics) | Descriptive statistics, binomial/normal distributions, normality and hypothesis tests | Python (SciPy, pandas) |
| [Desenvolvimento Web](Desenvolvimento%20Web) (Web Development) | HTML/CSS, DOM and Canvas, Express servers, EJS views, MongoDB CRUD | HTML, CSS, JavaScript, Node.js |
| [Computação Gráfica](Computa%C3%A7%C3%A3o%20Gr%C3%A1fica) (Computer Graphics) | 2D projection, Hermite and Bézier curves | C++ (OpenGL / freeglut) |
| [Computação Móvel](Computa%C3%A7%C3%A3o%20M%C3%B3vel) (Mobile Computing) | Arduino sensors and actuators; React and React Native apps | Arduino C++, JavaScript |
| [Sistemas Operacionais](Sistemas%20Operacionais) (Operating Systems) | Memory layout, `fork`, POSIX threads, race conditions, scheduler simulator, system calls | C (Linux) |
| [Sistemas Distribuídos](Sistemas%20Distribuidos) (Distributed Systems) | Multithreaded speedup (Amdahl, Karp–Flatt); HTTP + TCP multi-process pipeline | Python (Flask, sockets) |

Each course folder has its own README with the list of activities and how to run them.

## Notes

- Some folders contain example code the instructor provided in class (for example, *Exemplos do Professor*). These files are marked as instructor examples in their headers and are kept only as reference for the exercises built on them.
- Build outputs, IDE settings and dependencies (`node_modules/`, `build/`, `dist/`, `*.class`, ...) are excluded through [.gitignore](.gitignore). Run `npm install` inside a Node.js project before starting it.
