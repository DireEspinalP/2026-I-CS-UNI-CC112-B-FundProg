# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build & Run

```bash
make          # compile all sources → ./main
make -B       # force full recompile
make clean    # remove .o files and binary
./main        # run the program
```

Compiler: `g++ -std=c++2b -Wall -g -pthread`. No test framework; demos are exercised by calling the appropriate `Demo*()` function from `main()`.

## Syncing from upstream

```bash
git remote add upstream https://github.com/ecuadros/2026-I-CS-UNI-CC112-B-FundProg.git
git fetch upstream
git checkout -b <branch> upstream/<branch>
git push -u origin <branch>
```

## Architecture

This is an incremental C++ course repo (CC112 — Fundamentos de Programación, UNI 2026-I). Each module introduces a concept; `main.cpp` wires the active demos together. All module entry points follow the naming convention `Demo*()`.

### Module layout

| File(s) | Concept |
|---|---|
| `arit.{h,cpp}` | Basic arithmetic operations |
| `util.{h,cpp}` | Utility/helper functions; comparison functions (`Mayor<T>`, `Menor<T>`) used by sorting |
| `sorting.{h,cpp}` | Template sorting (`BurbujaClasico`, `BurbujaRecursivo`) and binary search; comparison passed as function pointer/lambda |
| `punteros.{h,cpp}` | Raw pointer demos |
| `vector.{h,cpp}` | Raw dynamic-array functions (`CreateVector`, `ReadVector`, …) plus the **progression of abstraction demos** (Levels 1–5, see below) |
| `matrix.{h,cpp}` | Raw 2-D dynamic matrix template functions |
| `cvector.{h,cpp}` | `CVector3<T>` — first OOP encapsulation of a dynamic array |
| `cmatrix.h` | `CMatrix<T>` — OOP encapsulation of a 2-D matrix |
| `array2.h` | Level-2 free-function templates for arrays |
| `array3.h` | `Array3<T>` — class with templated `ApplyFunctionToAll` |
| `array4.h` | `Array4<T>` — adds variadic template `ApplyFunctionToAll(func, args...)` and `operator>>` / `operator<<` |
| `types.h` | Central type aliases (`TP`, `TI`, `T1`, `T2`, …); toggle signed/unsigned via `#define __U__` |

### Progression of abstraction (the pedagogical spine)

`vector.cpp` contains five demo levels that are the main teaching thread:

1. **Level 1** (`DemoPunteros2Vector`) — raw pointer + free functions
2. **Level 2** (`DemoPointersVector2`) — free-function templates (`array2.h`)
3. **Level 3** (`DemoPointersVector3`) — class with member template (`Array3`)
4. **Level 4** (`DemoPointersVector4`) — variadic template class (`Array4`), reads from file
5. **Level 5** (`DemoPointersVector5`) — same class, adds `operator>>` / `operator<<` overloads

### Key design conventions

- Template classes are fully defined in `.h` files (required for separate compilation).
- Comparison functions are passed as function pointers (`bool (*)(T,T)`) or template `Func` parameters — never hardcoded inside algorithms.
- Sorting and search algorithms (`BurbujaClasico`, `BinarySearch`) live in `sorting.h` and are reused by OOP classes (`CVector3::Sort` calls `BurbujaClasico`).
- `output2.txt` / `output3.txt` are intermediate data files written by Level 2/3 demos and read back by Level 4/5 demos — they must exist (or be generated) before running Level 4+.
