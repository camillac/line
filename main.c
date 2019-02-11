#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int circle(int x, int radius){
  return (int)sqrt(pow((double)(radius),2) - pow((double)(x), 2)) ;
}

int main() {

  screen s;
  color c;

  clear_screen(s);

  int origin[2];
  origin[0] = 250;
  origin[1] = 250;

  for (int x = 200; x >= 0; x-= 1){
    // set to green
    c.red = 0;
    c.green = MAX_COLOR;
    c.blue = 0;
    draw_line(origin[0], origin[1], origin[0] + x, origin[1] + circle(x, 200), s, c);
    // set to yellow
    c.red = MAX_COLOR;
    c.green = 0;
    draw_line(origin[0], origin[1], origin[0] + x, origin[1] - circle(x, 200), s, c);
    // set to yellow
    c.green = MAX_COLOR;
    draw_line(origin[0], origin[1], origin[0] - x, origin[1] + circle(x, 200), s, c);
    // set to blue
    c.red = 0;
    c.green = 0;
    c.blue = MAX_COLOR;
    draw_line(origin[0], origin[1], origin[0] - x, origin[1] - circle(x, 200), s, c);
  }

  //display(s);
  save_extension(s, "lines.png");
  printf("lines.png\n");
}
