
#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <Tile.h>
#include <vector>
#include <string>

class Board {
public:

   void addToBoard(Tile* t);
   int calcScoreFrom(std::string pos);
   void legalPlacementAt(std::string pos, Tile* t);
   std::vector<std::vector<Tile*>> getBoard();
   int getWidth();
   int getHeight();

private:
   std::vector<std::vector<Tile*>> board;
   int width;
   int height;
};

#endif // ASSIGN2_BOARD_H