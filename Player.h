
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <Tile.h>
#include <LinkedList.h>
#include <string>

class Player {
public:

   void updateScore(int x);
   bool hasTile(std::string tileCode);
   void replactTile(std::string tileCode, Tile* replacement);
   int getScore();

private:
   LinkedList hand;
   int score;
};

#endif // ASSIGN2_PLAYER_H