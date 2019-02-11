#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x, y, a, b, d;

  // if x1 < x0 or y1 < y0, switch the points
  if (x1 < x0){
    x = x1;
    x1 = x0;
    x0 = x;

    y = y1;
    y1 = y0;
    y0 = y;
  }
  else {
    x = x0;
    y = y0;
  }

  a = 2*(y1 - y0);
  b = 2*(x0 - x1);

  // OCTANT I and V: if 0 <= m <= 1 (using a and b for convenience)
  if (a >= 0 && a <= -b){
    // printf("octant I or V: (%d,%d) -> (%d,%d)\n", x, y, x1, y1);
    d = 2*a + b;
    while (x <= x1){
      plot(s, c, x, y);
      if (d > 0){
        y++;
        d += b;
      }
      x++;
      d += a;
    }
  }

  // OCTANT II and VI: if m > 1 or undefined
  else if ((-b == 0 && y1 > y0) || (a > -b)){
    // printf("octant II or VI: (%d,%d) -> (%d,%d)\n", x, y, x1, y1);
    d = a + 2*b;
    while (y <= y1){
      plot(s, c, x, y);
      if (d < 0){
        x++;
        d += a;
      }
      y++;
      d += b;
    }
  }

  // OCTANT VII and III: if m < -1
  else if ((-b == 0 && y1 > y0) || abs(a) > abs(b)){
    // printf("octant VII or III: (%d,%d) -> (%d,%d)\n", x, y, x1, y1);
    d = a - 2*b;
    while (y >= y1){
      plot(s, c, x, y);
      if (d > 0){
        x++;
        d += a;
      }
      y--;
      d -= b;
    }
  }
  // OCTANT VIII and IV: if -1 <= m < 0
  else {
    // printf("octant VIII or IV: (%d,%d) -> (%d,%d)\n", x, y, x1, y1);
    d = 2*a - b;
    while (x <= x1){
      plot(s, c, x, y);
      if (d < 0){
        y--;
        d -= b;
      }
      x++;
      d += a;
    }
  }
}
