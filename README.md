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
You may need to make slight modifications to the code - this is likely just to change the imported packages for ncurses, which has a different version specific to windows. You'll also need to have the `make` CLI tool installed in order to make use of the makefile: https://medium.com/@samsorrahman/how-to-run-a-makefile-in-windows-b4d115d7c516#:~:text=To%20run%20Makefile%20on%20Windows,steps%20on%20your%20Windows%20system.

Then, you *should* be able to run:
```
make run
```

Don't take my word for it.
