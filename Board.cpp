#include "Board.h"

int Board::getWidth() {
    return 26;
}

char Board::getHeight() {
       return 'Z';
}

void Board::addToBoard(Tile* t) {

}
bool Board::legalPlacementAt(std::string pos, Tile* t) {
    return false;
}