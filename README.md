# Tetris - C++ & Raylib

A fully-featured Tetris game built with C++ and the Raylib game library. This implementation includes all classic Tetris mechanics with a modern dark-themed UI, sound effects, and smooth gameplay.

![Tetris](https://img.shields.io/badge/Tetris-C++_Raylib-blue)
![Raylib](https://img.shields.io/badge/Raylib-5.0-green)

## Features

- **Classic Tetris Gameplay**: All 7 standard Tetromino pieces (I, J, L, O, S, T, Z)
- **Score System**: Points for clearing lines and fast drops
  - 1 line: 100 points
  - 2 lines: 300 points
  - 3 lines: 500 points
  - Soft drop: 1 point per cell
- **Next Block Preview**: See the upcoming piece
- **Sound Effects**: Audio feedback for rotations, line clears, and background music
- **Game Over Detection**: Automatic game over when blocks stack to the top
- **Restart Functionality**: Press any key to restart after game over
- **Smooth Controls**: Responsive keyboard input with WASD and arrow key support

## Controls

| Key | Action |
|-----|--------|
| `←` / `A` | Move Left |
| `→` / `D` | Move Right |
| `↓` / `S` | Soft Drop (faster fall + points) |
| `↑` / `Space` | Rotate Block |
| `Any Key` | Restart (when game over) |

## Requirements

- C++ Compiler (g++, clang++, or MSVC)
- Raylib 5.0 or later
- CMake or manual build configuration

## Project Structure

```
Tetrisa/
├── src/
│   ├── main.cpp          # Entry point and game loop
│   ├── game.h/cpp        # Game logic and state management
│   ├── grid.h/cpp        # Grid management and collision detection
│   ├── block.h/cpp       # Block base class
│   ├── blocks.cpp        # All 7 Tetromino definitions
│   ├── position.h/cpp    # Position structure
│   └── colors.h/cpp      # Color definitions
├── sounds/
│   ├── music.mp3         # Background music
│   ├── rotate.mp3        # Rotation sound effect
│   └── clear.mp3         # Line clear sound effect
├── lib/                  # Runtime DLL files (Windows)
└── output/               # Compiled executable
```

## Building the Project

### Using g++ (Linux/Mac)

```bash
g++ src/*.cpp -o tetris -lraylib -lopengl32 -lgdi32 -lwinmm
```

### Using g++ (Windows)

```bash
g++ src/*.cpp -o tetris.exe -lraylib -lopengl32 -lgdi32 -lwinmm
```

### Using CMake

```bash
mkdir build
cd build
cmake ..
make
```

## Running the Game

After compilation, run the executable:

```bash
./tetris          # Linux/Mac
tetris.exe        # Windows
```

**Note**: Ensure the `sounds/` directory and required font file are in the same directory as the executable.

## Game Mechanics

### Tetromino Pieces

The game includes all 7 classic Tetromino shapes:
- **I-Block**: Straight line (cyan)
- **J-Block**: L-shape (blue)
- **L-Block**: Reverse L-shape (orange)
- **O-Block**: Square (yellow)
- **S-Block**: S-shape (green)
- **T-Block**: T-shape (purple)
- **Z-Block**: Z-shape (red)

### Scoring

- Clear multiple lines at once for bonus points
- Use soft drop (↓/S) to earn extra points while placing blocks faster
- Score is displayed in real-time on the right panel

### Grid

- Standard 10 columns × 20 rows grid
- Blocks lock in place when they cannot move down
- Full rows are cleared automatically
- Game ends when new blocks cannot spawn

## Technical Details

- **Language**: C++
- **Graphics Library**: Raylib 5.0
- **Window Size**: 600×620 pixels
- **Target FPS**: 120
- **Audio**: Raylib audio system with MP3 support
- **Font**: Custom font (zorque.ttf) - ensure this file exists in `resources/` directory

## Dependencies

- Raylib (install from https://www.raylib.com/)
- Standard C++ libraries
- Audio device support for sound effects

## License

This project is open source and available for educational purposes.

## Contributing

Feel free to fork this project and submit pull requests for improvements, bug fixes, or new features!

## Acknowledgments

- Built with [Raylib](https://www.raylib.com/) - A simple and easy-to-use library to enjoy videogames programming
- Classic Tetris gameplay mechanics inspired by the original game by Alexey Pajitnov
