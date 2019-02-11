#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int circle(int x, int radius){
  return (int)sqrt(pow((double)(radius),2) - pow((double)(x), 2)) ;
}

int main() {

  srand( time(NULL) );

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  int origin[2];
  origin[0] = 250;
  origin[1] = 250;

  for (int x = 200; x >= 0; x-= 1){
    c.red = MAX_COLOR - x;
    draw_line(origin[0], origin[1], origin[0] + x, origin[1] + circle(x, 200), s, c);
    draw_line(origin[0], origin[1], origin[0] + x, origin[1] - circle(x, 200), s, c);
    draw_line(origin[0], origin[1], origin[0] - x, origin[1] + circle(x, 200), s, c);
    draw_line(origin[0], origin[1], origin[0] - x, origin[1] - circle(x, 200), s, c);
  }

  c.red = MAX_COLOR;
  c.green = 0;
  c.blue = 0;

  draw_line(249, 51, 250, 250, s, c);

  //display(s);
  save_extension(s, "lines.png");
  printf("lines.png\n");
}
