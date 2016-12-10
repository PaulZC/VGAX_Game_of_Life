// Conway's Game Of Life for VGAX on Arduino Uno
// By: PaulZC
//
// The Rules:
//
// For a space that is 'populated':
//   Each cell with one or no neighbors dies, as if by solitude.
//   Each cell with four or more neighbors dies, as if by overpopulation.
//   Each cell with two or three neighbors survives.
// For a space that is 'empty' or 'unpopulated':
//   Each cell with three neighbors becomes populated.
//
// A live cell contains 3
// A cell about to die contains 2
// A cell about to spawn contains 1
// An empty/dead cell contains 0
//
// Follow Sandro's excellent instructions at https://github.com/smaffer/vgax
// But connect your VGA red, green _and_ blue wires to Arduino pin 7 via
// a single 470R resistor (ignore Arduino pin 6)
// That way you'll get a white pixel for cells containing a 3 or a 2
// and a black pixel for cells containing a 0 or a 1
//
// With thanks to: https://bitstorm.org/gameoflife/
//
// The version of the game coded here wraps the botttom edge to the top
// and the left edge to the right. This unfortunately means the Gosper Glider Gun
// ends up shooting itself!

#include <VGAX.h>

VGAX vga;

void setup() {
  vga.begin();
  vga.clear(0);

//  // Glider
//  vga.putpixel(2, 1, 3);
//  vga.putpixel(3, 2, 3);
//  vga.putpixel(1, 3, 3);
//  vga.putpixel(2, 3, 3);
//  vga.putpixel(3, 3, 3);

//  // Exploder
//  vga.putpixel(58, 28, 3);
//  vga.putpixel(58, 29, 3);
//  vga.putpixel(58, 30, 3);
//  vga.putpixel(58, 31, 3);
//  vga.putpixel(58, 32, 3);
//  vga.putpixel(60, 28, 3);
//  vga.putpixel(60, 32, 3);
//  vga.putpixel(62, 28, 3);
//  vga.putpixel(62, 29, 3);
//  vga.putpixel(62, 30, 3);
//  vga.putpixel(62, 31, 3);
//  vga.putpixel(62, 32, 3);

  // Gosper Glider Gun
  vga.putpixel(1, 10, 3);
  vga.putpixel(1, 11, 3);
  vga.putpixel(2, 10, 3);
  vga.putpixel(2, 11, 3);
  vga.putpixel(35, 8, 3);
  vga.putpixel(35, 9, 3);
  vga.putpixel(36, 8, 3);
  vga.putpixel(36, 9, 3);
  vga.putpixel(9, 11, 3);
  vga.putpixel(9, 12, 3);
  vga.putpixel(10, 10, 3);
  vga.putpixel(10, 12, 3);
  vga.putpixel(11, 10, 3);
  vga.putpixel(11, 11, 3);
  vga.putpixel(23, 9, 3);
  vga.putpixel(23, 10, 3);
  vga.putpixel(24, 8, 3);
  vga.putpixel(24, 10, 3);
  vga.putpixel(25, 8, 3);
  vga.putpixel(25, 9, 3);
  vga.putpixel(17, 12, 3);
  vga.putpixel(17, 13, 3);
  vga.putpixel(17, 14, 3);
  vga.putpixel(18, 12, 3);
  vga.putpixel(19, 13, 3);
  vga.putpixel(36, 15, 3);
  vga.putpixel(36, 16, 3);
  vga.putpixel(36, 17, 3);
  vga.putpixel(37, 15, 3);
  vga.putpixel(38, 16, 3);
  vga.putpixel(25, 20, 3);
  vga.putpixel(25, 21, 3);
  vga.putpixel(26, 20, 3);
  vga.putpixel(26, 22, 3);
  vga.putpixel(27, 20, 3);
}

void loop() {
  // loop through each cell and count how many neighbours it has
  for (int y=0; y!=VGAX_HEIGHT; y++) { // for each row
    for (int x=0; x!=VGAX_WIDTH; x++) { // for each column
      int neighbours = 0; // reset the number of neighbours
      for (int yn=y-1; yn<=y+1; yn++) { // for each of the neighbouring rows
        int ynw = yn;
        if (ynw == -1) ynw = VGAX_HEIGHT - 1; // handle wrap-around for top edge
        if (ynw == VGAX_HEIGHT) ynw = 0; // handle wrap-around for bottom edge
        for (int xn=x-1; xn<=x+1; xn++) { // for each of the neighbouring columns
          int xnw = xn;
          if (xnw == -1) xnw = VGAX_WIDTH - 1; // handle wrap-around for left edge
          if (xnw == VGAX_WIDTH) xnw = 0; // handle wrap-around for right edge
          if (vga.getpixel(xnw,ynw) >= 2) { // count the neighbours (include dying neighbours)
            neighbours++;
          }
        }
      }
      // check if live cell is lonely or overcrowded
      // (the number of neighbours includes the cell itself)
      if ((vga.getpixel(x,y) == 3) && ((neighbours <= 2) || (neighbours >= 5))) {
        vga.putpixel(x,y,2); // mark cell as about to die
      }
      // check if empty cell should spawn
      if ((vga.getpixel(x,y) == 0) && (neighbours == 3)) {
        vga.putpixel(x,y,1); // mark cell as about to spawn
      }
    }
  }
  // loop through the cells again and update dying and spawning cells
  for (int y=0; y!=VGAX_HEIGHT; y++) { // for each row
    for (int x=0; x!=VGAX_WIDTH; x++) { // for each column
      if (vga.getpixel(x,y) == 2) vga.putpixel(x,y,0); // Make dying cell dead
      if (vga.getpixel(x,y) == 1) vga.putpixel(x,y,3); // Make spawning cell live
    }
  }
}
