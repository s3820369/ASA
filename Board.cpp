#include "Board.h"

Board::Board() {
    width = COLUMNS;
    height = ROWS;
    board.resize(BOARD_SIZE);

    for(int i = 0; i < ROWS - 'A' + 1; ++i) {
        board[i] = std::vector<Tile*>(BOARD_SIZE);

        for(int j = 0; j < COLUMNS; ++j) {
            board[i][j] = nullptr;
        }
    }
}

void Board::addToBoard(Tile* t, int x, int y) {
    board[y][x] = t;
}


int Board::calcScoreFrom(int x, int y, Tile* g) {
    // adding the points from the row
    // adding the points for columns
    //checking if sthers a qwirkle
    int i;
    char row = y;
    int rowDown = 'Z' - row;
   // int rowRight = abs(row - 'A');
    char col = x;
    int ColNum = col - '0';
    int scoreRowUp = 0;
    int scoreRowDown= 0;
    int scoreColRight = 0;
    int scoreColLeft= 0;
    bool stop = false;
    
    while(!stop){
        for(i = row;i<='Z';i++){        //rowDown
            
            int h = 'Z' - i;
            if(board[h][ColNum] != nullptr){
                scoreRowDown++;
            }else{
                stop = true;
            }
        }
    }
    stop = false;
    while(!stop){
        for(i = row - 1;i<='A';i--){      //rowUp
            int f = i - 'A';
                if(board[f][ColNum] != nullptr){
                    scoreRowUp++;
                }else{
                    stop = true;
                }
            
        }
    }
    int totalRowScore = scoreRowDown + scoreRowUp;
    stop = false;
    while(!stop){
        for(int g = ColNum;g< BOARD_SIZE;g++){
            if(board[rowDown][ColNum] != nullptr){
                scoreColRight++;
            }else{
                stop = true;
            }
        }
    }
    stop = false;
    while (!stop)
    {
        for(int a = ColNum - 1;a<=0;a--){
            if(board[rowDown][ColNum] != nullptr){
                scoreColLeft++;
            }else{
                stop = true;
            }
        }
    }
    int tot = totalRowScore + scoreColLeft + scoreColRight;
    return tot;


}


bool Board::legalPlacementAt(int x, int y, Tile* tile) {
    return isLegalVerticalCheck(tile, x, y, 0, ROWS)      &&
           isLegalHorizontalCheck(tile, x, y, 0, COLUMNS) &&
           nullptr == board[row][col];
}

bool Board::isLegalVerticalCheck(Tile* placing, int x, int y, int lower, int upper) {
    bool sameTile = false;
    bool diffShape = false;
    bool diffColour = false;
    int i = y;

    if(upper != y)
        y += 1;
        
    Tile* tile = board[i][x];

    while(i < upper && tile != nullptr) {
        checkConditions(placing, tile, diffColour, diffShape, sameTile);
        tile = board[++i][x];
    }

    i = y;

    if(lower != y)
        y -= 1;

    tile = board[i][x];

    while(i >= lower && tile != nullptr) {
        checkConditions(placing, tile, diffColour, diffShape, sameTile);
        tile = board[--i][x];
    }
    return !((diffColour && diffShape) || sameTile);
}

bool Board::isLegalHorizontalCheck(Tile* placing, int x, int y, int lower, int upper) {
    bool sameTile = false;
    bool diffShape = false;
    bool diffColour = false;
    int i = x;

    if(upper != x)
        x += 1;

    Tile* tile = board[y][i];

    while(i < upper && tile != nullptr) {
        checkConditions(placing, tile, diffColour, diffShape, sameTile);
        tile = board[y][++i];
    }

    i = x;

    if(lower != x)
        x -= 1;

    tile = board[y][i];

    while(i >= lower && tile != nullptr) {
        checkConditions(placing, tile, diffColour, diffShape, sameTile);
        tile = board[y][--i];
    }
    return !((diffColour && diffShape) || sameTile);
}

void Board::checkConditions(Tile* placing, Tile* checking, bool& diffColour,
                            bool& diffShape, bool& sameTile) {
     
    if(placing->colour != checking->colour) diffColour = true; 
    if(placing->shape  != checking->shape)  diffShape = true;
    if(!diffColour     && !diffShape)       sameTile = true;
}

Tile* Board::getAt(int x, int y) {
    return board[y][x];
}

int Board::getWidth() {
    return width;
}

int Board::getHeight() {
    return height;
}

std::ostream& operator<<(std::ostream &out, const Board& board) {
    for(int i = 0; i < ROWS; ++i) {

        for(int j = 0; j < COLUMNS; ++j) {
            Tile* tile = board.getAt(i, j);

            if(nullptr != tile)
                out << tile << '@' <<   (char)(i + 'A') << j << " ";
        }
    }
}