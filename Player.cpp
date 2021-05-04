#include "Player.h"
   
void Player::replaceTile(Tile* tile, Tile* replacement) {
    int index = -1;
    for(int i = 0; i < hand.size(); ++i) {
        if(hand.at(i) == tile)
            index = i;
    }
    hand.remove(index);
    hand.insert(index, replacement);   
}

Tile* Player::getTile(std::string tileCode) {
    Tile* retTile = nullptr;

    for(int i = 0; i < hand.size(); ++i) {
        Tile* tile = hand.at(i);
        
        if(tile->colour == tileCode[0] && tile->shape == tileCode[1])
            retTile = tile;
    }
    return retTile;
}

void Player:: updateScore(int x) {
    score += x;
}

int Player::getScore() {
    return score;
}

LinkedList& Player::getHand() {
    return hand;
}

