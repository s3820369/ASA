
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <Tile.h>
#include <LinkedList.h>
#include <string>

class Player {
   public:
      
      // Update the player's score
      void updateScore(int x);

      // Replace tile in hand with incoming tile
      void replaceTile(Tile* tile, Tile* replacement);

      // return specified tile
      Tile* getTile(std::string tileCode);

      // Get hand
      LinkedList& getHand();

      // Get a const reference for passing to stream
      const LinkedList& getHandConst() const;
      
      // Get scure
      int getScore() const;

      // Get name
      std::string getName() const;

   private:
      // Player name
      std::string name;

      // List of player tiles
      LinkedList hand;

      // PLayer score
      int score;
};

#endif // ASSIGN2_PLAYER_H