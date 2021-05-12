#include <iostream>
#include <stdexcept>
#include "Board.h"

// ill have positions 
char i;
int j = 0;


Board::Board() {
    width = 0;
    height = 0;
    this->board.resize(26);

    for(int g = 0; g < 26; g++) {
        std::vector<Tile*> temp;
        this->board[i] = std::vector<Tile*>(26);

        for(int k = 0; k < 26; k++) {
            this->board[i][j] = nullptr;
        }
    }

}

void Board::addToBoard(Tile* t,std::string pos) {
    std::vector<int> v(26);
    for(char f = 'A'; f <= 'Z'; f++)
    {
        v[f] = j;
        j++;
    }
    char Row = pos[0];
    char Col = pos[1];
    int row = 'Z' - Row;
    int ColNum = Col - '0';
    // take the position of the tile. and say that position as the tile
    this->board[row][ColNum] = new Tile(*t);
}


int Board::calcScoreFrom(std::string pos, Tile* g) {
    // adding the points from the row
    // adding the points for columns
    //checking if thers a qwirkle
    std::vector<int> v(26);
    for(char k = 'A'; k <= 'Z'; k++)
    {
        v[j] = k;
        j++;
    }
    char row = pos[0];
    int rowDown = 'Z' - row;
    int rowRight = abs(row - 'A');
    char col = pos[1];
    int ColNum = col - '0';
    int scoreRowUp = 0;
    int scoreRowDown= 0;
    int scoreColRight = 0;
    int scoreColLeft= 0;
    bool stop = false;
    
    while(!stop) {
        for(i = row;i<='Z';i++) {        //rowDown
            
            int h = 'Z' - i;
            if(board[h][ColNum] != nullptr) {
                scoreRowDown++;
            } else {
                stop = true;
            }
            
            
        }
    }
    stop = false;
    while(!stop) {
        for(i = row - 1;i<='A';i--) {      //rowUp
            int f = i - 'A';
            if(board[f][ColNum] != nullptr) {
                scoreRowUp++;
            } else {
                stop = true;
                }
        }
    }
    int totalRowScore = scoreRowDown + scoreRowUp;

    for(int g = ColNum;g< COLUMN_SIZE;g++) {
        if(board[rowDown][ColNum] != nullptr) {
            scoreColRight++;
        }
    } 
    for(int a = ColNum - 1;a<=0;a--) {
        if(board[rowDown][ColNum] != nullptr) {
            scoreColLeft++;
        }
    }
    int tot = totalRowScore + scoreColLeft + scoreColRight;
    // return tot?
}


bool Board::legalPlacementAt(std::string pos, Tile* t) {
    int x,y;
    bool v = islegalVerticalCheck(x, y, t);
    bool h = islegalHorizontalCheck(x, y, t);
    return false; // islegalVerticalCheck(x, y, t) &&islegalHorizontalCheck(x, y, t);
}

std::vector<std::vector<Tile*>> Board::getBoard() {
    return board;
}

int Board::getWidth() {
    return width;

}

int Board::getHeight() {
    return height;
}

int Board::getMaxCol() {

}

int Board::getMaxRow() {
    
}

bool Board::islegalVerticalCheck(int x, int y, Tile* t) {
    bool differentShape;
    bool differentColor;
    bool sameTile = false;
    int d = y+1;
    Tile* tile = board[d][x];

    while (d < 26 && tile != nullptr) {
        if (tile->colour == t->colour && tile->shape == t->shape) {
            sameTile = true;
        }
        if(tile->colour != t->colour) {
            differentColor = true;    
        }
        if(tile->shape != t->shape) {
            differentShape = true;
        }
        tile = board[++d][x];
    }

    d = y -1;
    tile = board[d][x];

    while(d >= 0 && tile != nullptr) {
        if (tile->colour == t->colour && tile->shape == t->shape) {
            sameTile = true;
        }
        if(tile->colour != t->colour) {
            differentColor = true;    
        }
        if(tile->shape != t->shape) {
            differentShape = true;
        }
        tile = board[--d][x];
    return !(differentShape && differentColor || sameTile);
    }
}
bool Board::islegalHorizontalCheck(int x, int y, Tile* t) {
    bool differentShape;
    bool differentColor;
    bool sameTile = false;
    int height = 26;
    int d = x+1;
    Tile* tile = board[y][d];

    while(d < 26 && tile != nullptr) {
        if(tile->colour == t->colour && tile->shape == t->shape) {
            sameTile = true;
        }
        if(tile->colour != t->colour) {
            differentColor = true;    
        }
        if(tile->shape != t->shape) {
            differentShape = true;
        }
        tile = board[y][d++];
    }

    d = y -1;
    tile = board[d][x];

    while (d >= 0 && tile != nullptr) {
        if (tile->colour == t->colour && tile->shape == t->shape) {
            sameTile = true;
        }
        if(tile->colour != t->colour) {
            differentColor = true;    
         }
        if(tile->shape != t->shape) {
            differentShape = true;
        }
        tile = board[y][--d];
    return !(differentShape && differentColor || sameTile);
    }
}

void Board::displayBoard() {
    char alphabets = 65;
}
