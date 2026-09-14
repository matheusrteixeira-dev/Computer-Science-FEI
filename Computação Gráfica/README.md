# Computação Gráfica (Computer Graphics)

OpenGL programs written in C++ with freeglut.

| Activity | File | Description |
| --- | --- | --- |
| [Atividade 01](Atividade%2001) | `main.cpp` | Basic OpenGL program: 2D orthographic projection of a triangle (based on the instructor's demo). |
| [Atividade 04](Atividade%2004) | `Curvas2DHermiteBezier.cpp` | Interactive 2D curve plotting: a parabola, a cubic Hermite curve and a Bézier curve whose control points are set by mouse clicks. Keys `P`, `H` and `B` switch between the modes. |

## Building

```bash
g++ "Atividade 04/Curvas2DHermiteBezier.cpp" -o curvas -lfreeglut -lopengl32 -lglu32   # MinGW (Windows)
g++ "Atividade 04/Curvas2DHermiteBezier.cpp" -o curvas -lglut -lGL -lGLU               # Linux
```
