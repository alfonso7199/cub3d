# cub3D

**Project completed with a score of 115/100 (including bonuses)**

A “realistic” 3D maze renderer built in C using **ray-casting techniques**, inspired by classic games like *Wolfenstein 3D*. This project was developed as part of the **42 Madrid School** curriculum and uses the **MiniLibX** graphical library.

## Main Features

### Core Features (Mandatory)
- **Real-time 3D rendering** using ray-casting
- **First-person perspective** navigation inside a maze
- **Different wall textures** depending on orientation:
  - North, South, East, West
- **Custom floor and ceiling colors**
- **Smooth window management** (minimize, focus, close, etc.)
- **Keyboard controls**:
  - `W`, `A`, `S`, `D` → Move player
  - `←`, `→` → Rotate view
  - `ESC` → Exit program
- **Clean program exit** via ESC or window close button
- **Strict `.cub` file parsing** with detailed error handling

### Bonus Features
- **Wall collisions**
- **Minimap system**
- **Mouse-based camera rotation**

## Technologies Used

- **Language**: C (C99)
- **Graphics**: MiniLibX
- **Math**: math.h (-lm)
- **System**: Unix / Linux
- **Compiler**: GCC / Clang
- **Build system**: Makefile

## Installation and Usage

### Prerequisites

    # Ubuntu / Debian
    sudo apt-get install libxext-dev libx11-dev libbsd-dev

    # macOS (with Homebrew)
    brew install minilibx

### Compilation

    make

### Execution

    ./cub3D maps/example.cub

## Map Format (.cub)

The program takes a **scene description file** with the .cub extension.

### Map Rules
- Valid characters:
  - 0 → Empty space
  - 1 → Wall
  - N, S, E, W → Player start position and orientation
- The map **must be closed / surrounded by walls**
- Spaces are considered part of the map and must be handled correctly
- The map must be the **last element** in the file

### Required Elements

    NO ./path_to_north_texture
    SO ./path_to_south_texture
    WE ./path_to_west_texture
    EA ./path_to_east_texture
    F 220,100,0
    C 225,30,0

### Example .cub File

    NO ./textures/north.xpm
    SO ./textures/south.xpm
    WE ./textures/west.xpm
    EA ./textures/east.xpm
    F 220,100,0
    C 225,30,0

    111111
    100101
    101001
    1100N1
    111111

If any misconfiguration is detected, the program exits with:

    Error
    <explicit error message>

## Controls Summary

| Input         | Action              |
|---------------|---------------------|
| W / A / S / D | Move player         |
| ← / →         | Rotate view         |
| Mouse         | Rotate view (bonus) |
| ESC           | Exit program        |
| Window close  | Exit program        |

## 👥 Authors

**42 Madrid School**
- **Alfonso Sánchez** - @alfonso7199
- **Rafael Zamolo Tanganelli** - @rzamolo-
