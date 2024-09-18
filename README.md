# terminal_game_engine
[attempting] to build a game engine for the terminal using the ncurses module and c++ (or c, depending on how things go)).
With help from the channel: https://www.youtube.com/@KayOScode

NOTE:

In its current state, the program can:
- Perform translations, rotations and enlargements to vectors
- Rasterise triangles
- Render aforementioned triangles
- Load in and subsequently render `.obj` files
- **Do all of the above using a shader to emulate a light source at a specified location**
- and probably more, I can't remember

## To run

### On unix systems (mac/ linux):
```
make run
```
making use of the make file in the root directory. Or you can compile yourself directly using gcc or something maybe.

### On windows:
You're on your own
