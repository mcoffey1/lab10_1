// Matthew Coffey
// symbol.cpp

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "gfx.h"


const double PI = atan(1)*4;
const int SIZE = 26;
int main()
{
  int wd = 1000, ht = 1000;
  bool loop = true;
  char c;
  int input;
  
  gfx_open(wd, ht, "Symbolic Typewriter");
  gfx_clear();

  while (true){
    c = gfx_wait();
    input = int(c);
    int x = gfx_xpos(), y = gfx_ypos();
    if (c >= 51 && c <= 57){
	gfx_color(255, 0, 255); 
	double ang, ang2;
	for (int i = 0; i < c-48; i++){
	  ang  = 2 * PI * i / (c-48);
	  ang2 = 2 * PI * (i+1)/(c-48);
	  gfx_line(x + SIZE * cos(ang), y + SIZE * sin(ang), x+SIZE*cos(ang2), y+SIZE*sin(ang2));

	}
    }
    else {
      switch (input){
	case 1:
 	  gfx_color(0, 0, 255);
	  x = gfx_xpos()-SIZE/2; 
	  y = gfx_ypos()-SIZE/2;
            gfx_line(x, y, x+SIZE, y);
            gfx_line(x+SIZE, y, x+SIZE, y+SIZE);
	    gfx_line(x+SIZE, y+SIZE, x, y+SIZE);
	    gfx_line(x, y+SIZE, x, y);
	 
 	  break;
	case 99:
	  gfx_color(255, 255, 255);
	  gfx_circle(gfx_xpos(), gfx_ypos(), SIZE);
	  break;
	case 116:
	  x = gfx_xpos()-SIZE/3;
	  y = gfx_ypos()-SIZE/3;
	  gfx_color(0, 255, 0);
	  gfx_line(x+SIZE, y, x, y+SIZE);
	  gfx_line(x, y, x+SIZE, y);
	  gfx_line(x, y, x, y+SIZE);
     	  break;
	case 27:
	  gfx_clear();
	  break;
	case 113:
	  return 0;
 	  break;		
        default:
	  break;
      }
    }
  }
  return 0;
}

 
