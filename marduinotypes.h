
#ifndef MARDUINOTYPES_H
#define MARDUINOTYPES_H

typedef const unsigned char PROGMEM BMP;
typedef const unsigned int PROGMEM TILEMAPSET;

struct Vector2f {
float x;
float y;

Vector2f(float xx, float yy) {
  x = xx;
  y = yy;
};

};

#endif
