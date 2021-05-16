#include "Player.h"
#include "Util.h"


Player::~Player() {
  //  delete hand;
}
Player::Player() : score(0) {}
Player::Player(std::string name) : name(name), score(0) {
   // hand = new LinkedList();
}

Player::Player(Parser::PlayerInfo_t info) {
 //   hand = new LinkedList();
    name = info.name;
    score = info.score;

    for(unsigned int i = 0; i < info.hand.size(); ++i) {
        char colour = info.hand[i][0];
        int  shape  = info.hand[i][1];
        hand.push_back(new Tile(colour, charToInt(shape)));
        std::cout << *hand.at(i) << std::endl;
    }
    std::cout << &hand << std::endl;
}

void Player::replaceTile(Tile* tile, Tile* replacement) {
    hand.remove(tile);
    if(replacement != nullptr)
        hand.push_back(replacement);
}

Tile* Player::getTile(std::string tileCode) {
    Tile* retTile = nullptr;

    for(int i = 0; i < hand.size(); ++i) {
        Tile* tile = hand.at(i);
        
        if(tile->colour == tileCode[0] && tile->shape == charToInt(tileCode[1]))
            if(nullptr == retTile)
                retTile = tile;
    }
    return retTile;
}

void Player:: updateScore(int x) {
    score += x;
}

int Player::getScore() const {
    return score;
}

const LinkedList& Player::getHandConst() const {
    return hand;
}

LinkedList& Player::getHand() {
    return hand;
}

std::string Player::getName() const {
    return name;
}

bool operator==(const Player& p1, const Player& p2) {
   return p1.getName() == p2.getName();
}

bool operator!=(const Player& p1, const Player& p2) {
   return !(p1 == p2);
}