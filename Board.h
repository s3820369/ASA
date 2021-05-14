
#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include <string>
#include <cmath>
#include "Tile.h"
#include "Util.h"

#define BOARD_SIZE   26
#define COLUMNS      26
#define ROWS         'Z'

class Board {
   
public:
   Board();
   void addToBoard(Tile* t,std::string pos);
   int calcScoreFrom(std::string pos,Tile* g);
   bool legalPlacementAt(std::string pos, Tile* t);
   int getWidth();
   int getHeight();
   int getMaxRow();
   int getMaxCol();
   void displayBoard();  

   Tile* getAt(int x, int y);

private:
   std::vector<std::vector<Tile*>> board;
   int width;
   int height;

   bool isLegalVerticalCheck(Tile* comparingTo, int startX, int startY,
                             int lower, int upper);

   bool isLegalHorizontalCheck(Tile* comparingTo, int startX, int startY,
                               int lower, int upper);

   void checkConditions(Tile* placingTile, Tile* comparingTo,
                        bool& diffColour, bool& diffShape, bool& sameTile);
};

#endif // ASSIGN2_BOARD_H