# 🕹️ so\_long

Small 2D game built with MiniLibX as part of the 42 School curriculum. Demonstrates window management, event handling, and simple game mechanics in C.

---

## Build and run

**Requirements:** C compiler, `make`, MiniLibX (included as a submodule), **X11** development headers, and **libbsd**.

```bash
# Clone
git clone --recurse-submodules https://github.com/cmunoz-g/so_long.git
cd so_long

# Build
make

# Run\./so_long path/to/map.ber
```

Replace `path/to/map.ber` with the path to your map file.

**Note (macOS):** Replace the `Makefile` and `minilibx` folder with those inside the `MacOS/` directory before building.

---

## Features

* **Player movement** with `W`, `A`, `S`, `D`.
* **Objective**: collect all collectibles then reach the exit.
* **Sprite animation** based on player direction.
* **Terminal feedback**: move count displayed after each action.
* **Top-down 2D view** rendered via MiniLibX.

---

## Map requirements

* **Walls (`1`)** fully enclose the map.
* **Empty space (`0`)** for player movement.
* **Collectibles (`C`)** at least one present.
* **Exit (`E`)** exactly one.
* **Player start (`P`)** exactly one.

---

## Path validation

Uses a **Breadth-First Search (BFS)** to verify the player can collect all `C` items and reach `E` without obstruction.

---
