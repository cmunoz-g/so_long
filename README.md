# 🕹️ so_long

## Introduction
**so_long** is a small 2D game developed as part of the 42 School curriculum. It is designed to work with graphical assets such as textures and sprites, using the MiniLibX library for graphical rendering. The goal of the project is to help understand the basics of window management, event handling, and simple game mechanics in C.

## Project Description
In this game, the player controls a character on a 2D map, collecting items and navigating to the exit while avoiding obstacles. The project includes basic functionality like movement control, collision detection, and a sprite change depending on the player's direction.

### Game Features
- **Player Movement**: Use `W`, `A`, `S`, `D` keys to move the character up, left, down, and right, respectively.
- **Objective**: Collect all the items on the map and reach the exit.
- **Sprite Animation**: The player's sprite changes based on the direction the player is facing.
- **Terminal Feedback**: The number of moves is displayed in the terminal after each action.
- **2D Perspective**: The game is presented in a simple 2D top-down view.

### Map Requirements
The game requires a map file in `.ber` format. The map must meet the following conditions to be considered valid:
- **Walls (`1`)**: The map must be completely enclosed by walls, with no gaps.
- **Empty Space (`0`)**: Areas where the player can move freely.
- **Collectibles (`C`)**: There must be at least one collectible item for the player to collect.
- **Exit (`E`)**: The map must have one exit, which the player can reach after collecting all items.
- **Player Start Position (`P`)**: The map must have one starting position for the player.

### Path Validation
A valid map must have a clear path that allows the player to collect all items (`C`) and then reach the exit (`E`). To ensure this, the implementation uses a **Breadth-First Search (BFS) algorithm**. The BFS checks that there is a viable path for the player to traverse the entire map, collect all collectibles, and reach the exit without any obstructions.

## Installation and Usage
1. **Clone the Repository**:
    ```bash
    git clone https://github.com/cmunoz-g/so_long.git
    ```
2. **Navigate to the Project Directory**:
    ```bash
    cd so_long
    ```
3. **Compile the Program**:
    ```bash
    make
    ```
4. **Run the Game**:
    ```bash
    ./so_long path/to/map.ber
    ```
   Replace `path/to/map.ber` with the path to your map file.

Enjoy the minigame! 🎮
