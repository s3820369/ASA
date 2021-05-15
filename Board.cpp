#include "Board.h"

Board::Board() {
    width = COLUMNS;
    height = ROWS;
    board.resize(BOARD_SIZE);
    firstTilePlaced = false;
    
    for(int i = 0; i < ROWS_INT + 1; ++i) {
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

bool Board::hasAdjacent(int x, int y, int xLow, int xHigh, int yLow, int yHigh) {
    bool hasAdjacent = true;
    
    if     (yHigh != y && nullptr != board[y+1][x]);
    else if(yLow  != y && nullptr != board[y-1][x]);
    else if(xHigh != x && nullptr != board[y][x+1]);
    else if(xLow  != x && nullptr != board[y][x-1]);
    else    hasAdjacent = false;
    return hasAdjacent;
}

bool Board::legalPlacementAt(int x, int y, Tile* tile) {
    bool legal = isLegalVerticalCheck(tile, x, y, 0, ROWS_INT)  &&
                 isLegalHorizontalCheck(tile, x, y, 0, COLUMNS) &&
                 nullptr == board[y][x];

    if(firstTilePlaced)
        legal = legal && hasAdjacent(x, y, 0, COLUMNS, 0, ROWS_INT);
    else
        firstTilePlaced = true;

    return legal;
}

bool Board::isLegalVerticalCheck(Tile* placing, int x, int y, const int lower, const int upper) {
    bool sameTile = false;
    bool diffShape = false;
    bool diffColour = false;
    int i = y;
    
    // If not edge, increment i so that it starts above where placing
    if(upper != y)
        i += 1;
        
    Tile* tile = board[i][x];

    while(i < upper && tile != nullptr) {
        checkConditions(placing, tile, diffColour, diffShape, sameTile);
        ++i;
        if(upper != i)
            tile = board[i][x];
    }

    i = y;

    // If not edge, decrement i so that itstarts below where placing
    if(lower != y)
        i -= 1;

    tile = board[i][x];

    while(i >= lower && tile != nullptr) {
        checkConditions(placing, tile, diffColour, diffShape, sameTile);
        --i;
        if(lower < i)
            tile = board[i][x];
    }

    return !((diffColour && diffShape) || sameTile);
}

bool Board::isLegalHorizontalCheck(Tile* placing, int x, int y, const int lower, const int upper) {
    bool sameTile = false;
    bool diffShape = false;
    bool diffColour = false;
    int i = x;

    // If not edge, increment i so that it starts to the right of where placing
    if(upper != x)
        i += 1;

    Tile* tile = board[y][i];

    while(i < upper && tile != nullptr) {
        checkConditions(placing, tile, diffColour, diffShape, sameTile);
        ++i;
        if(upper != i)
            tile = board[y][i];
    }

    i = x;

    // If not edge, decrement i so that it starts to the left of where placing
    if(lower != x)
        i -= 1;

    tile = board[y][i];

    while(i >= lower && tile != nullptr) {
        checkConditions(placing, tile, diffColour, diffShape, sameTile);
        --i;
        if(lower != i)
            tile = board[y][i];
    }

    return !((diffColour && diffShape) || sameTile);
}

void Board::checkConditions(Tile* placing, Tile* checking, bool& diffColour,
                            bool& diffShape, bool& sameTile) {
     
    if(placing->colour != checking->colour) diffColour = true; 
    if(placing->shape  != checking->shape)  diffShape = true;
    if(!diffColour     && !diffShape)       sameTile = true;
}

Tile* Board::getAt(int x, int y) const {
    return board[y][x];
}

int Board::getWidth() {
    return width;
}

int Board::getHeight() {
    return height;
}
