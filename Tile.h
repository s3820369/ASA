
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <string>

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
   public:
      Tile(Colour colour, Shape shape);
      Colour colour;
      Shape  shape;
      char getColor();
      int getShape();
};

bool operator==(const Tile tile1, const Tile tile2);

#endif // ASSIGN2_TILE_H
