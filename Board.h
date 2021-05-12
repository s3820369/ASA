
#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include <string>
#include <cmath>

#include "Tile.h"

#define COLUMN_SIZE     26
#define ROW_SIZE        26
#define BOARD_SIZE      26

class Board {
public:

   void addToBoard(Tile* t, std::string pos);
   int calcScoreFrom(std::string pos, Tile* g);
   bool legalPlacementAt(std::string pos, Tile* t);
   bool islegalVerticalCheck(int x, int y, Tile* t);
   bool islegalHorizontalCheck(int x, int y, Tile* t);
   int getWidth();
   int getHeight();
   int getMaxRow();
   int getMaxCol();
   void displayBoard();
   std::vector<std::vector<Tile*>> getBoard();

private:
   std::vector<std::vector<Tile*>> board;
   int width;
   int height;
};

#endif // ASSIGN2_BOARD_H