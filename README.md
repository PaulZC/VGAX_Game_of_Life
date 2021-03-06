# VGAX Game of Life

If, like me, you're of a certain age, you'll remember that Sun Microsystems
workstations used to use Conway's Game of Life as a screensaver.

When I saw Sandro Maffiodo's VGAX for the Arduino Uno, I thought it might be
the perfect tool to recreate the game of life. And it is!

The Rules:

For a space that is 'populated':
- Each cell with one or no neighbors dies, as if by solitude.
- Each cell with four or more neighbors dies, as if by overpopulation.
- Each cell with two or three neighbors survives.

For a space that is 'empty' or 'unpopulated':
- Each cell with three neighbors becomes populated.

In this version:

- A live cell contains the value 3
- A cell about to die contains the value 2
- A cell about to spawn contains the value 1
- An empty/dead cell contains the value 0

Follow [Sandro's excellent instructions](https://github.com/smaffer/vgax)
but connect your VGA red, green _and_ blue wires to Arduino pin 7 via
a single 470R resistor (ignore Arduino pin 6). That way you'll get a white
pixel for cells containing a 3 or a 2 and a black pixel for cells containing
a 0 or a 1

![Glider.gif](https://github.com/PaulZC/VGAX_Game_of_Life/blob/master/Rules_of_Conway's_game_of_life_-_Glider.gif)

Image credit: https://en.wikipedia.org/wiki/File:Rules_of_Conway%27s_game_of_life_-_Glider.gif

With thanks to: https://bitstorm.org/gameoflife/

The version of the game coded here wraps the botttom edge to the top
and the left edge to the right. This unfortunately means the Gosper Glider Gun
ends up shooting itself!

Enjoy!

Paul
