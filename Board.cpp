#include "Board.h"

#define QWIRKLE     6;

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

Board::Board(Parser::BoardState_t state) {
    width = state.width;
    height = state.height;

    for(int i = 0; i < height - 'A' + 1; ++i) {
        board.push_back(std::vector<Tile*>(width));
    }

    for(unsigned int i = 0; i < state.unparsedBoard.size(); ++i) {
        std::vector<std::string> tilePos = splitString(state.unparsedBoard[i], "@");
        Tile* tile = new Tile(tilePos[0][0], charToInt(tilePos[0][1]));
        int row = tilePos[1][0] - 'A';
        int col = -1;
        if(tilePos[1].length() == 3)    col += doubleDigitCol(tilePos[1]);
        else                            col += charToInt(tilePos[1][1]);
        board[row][col] = tile;
    }

}

void Board::addToBoard(Tile* t, int x, int y) {
    board[y][x] = t;
}


int Board::calcScoreFrom(int col, int row) {
    int i = 0;
    int columnScore = 0;
    int rowScore = 0;
    bool stop = false;

    for(i = row + 1; i < BOARD_SIZE && !stop; i++) {        
        if(board[i][col] != nullptr) {
            rowScore++;
        } else {
            stop = true;
        }
    }

    stop = false;

    // Row up
    for(i = row - 1; i >= 0 && !stop; i--) {
        if(board[i][col] != nullptr) {
            rowScore++;
        } else {
            stop = true;
        } 
    }

    stop = false;
    for(int g = col + 1; g < BOARD_SIZE && !stop; g++) {
        if(board[row][g] != nullptr) {
            columnScore++;
        } else {
            stop = true;
        }
    }

    stop = false;

    for(int a = col - 1; a >= 0 && !stop; a--) {
        if(board[row][a] != nullptr) {
            columnScore++;
        } else {
            stop = true;
        }
    }

    if(columnScore > 0)
        columnScore++;

    if(rowScore > 0)
        rowScore++;

    if(!firstTilePlaced) {
        columnScore += 2;
        firstTilePlaced = true;
    }

    if(6 == columnScore)   columnScore += QWIRKLE;
    if(6 == rowScore)      rowScore += QWIRKLE;

    return rowScore + columnScore;
}

bool Board::hasAdjacent(int x, int y, int xLow, int xHigh, int yLow, int yHigh) {
    bool hasAdjacent = true;
    
    if     (yHigh  > y && nullptr != board[y+1][x]);
    else if(yLow  <= y && nullptr != board[y-1][x]);
    else if(xHigh  > x && nullptr != board[y][x+1]);
    else if(xLow  <= x && nullptr != board[y][x-1]);
    else    hasAdjacent = false;
    return hasAdjacent;
}


bool Board::legalPlacementAt(int x, int y, Tile* tile) {
    bool legal = isLegalVerticalCheck(tile, x, y, 0, ROWS_INT)  &&
                 isLegalHorizontalCheck(tile, x, y, 0, COLUMNS-1) &&
                 nullptr == board[y][x];

    if(firstTilePlaced)
        legal = legal && hasAdjacent(x, y, 0, COLUMNS, 0, ROWS_INT);
    return legal;
}

bool Board::isLegalVerticalCheck(Tile* placing, int x, int y, const int lower, const int upper) {
    bool sameTile = false;
    bool diffShape = false;
    bool diffColour = false;
    int i = y;
    
    // If not edge, increment i so that it starts above where placing
    if(y < upper)
        i += 1;
        
    Tile* tile = board[i][x];

    while(i < upper && tile != nullptr) {
        checkConditions(placing, tile, diffColour, diffShape, sameTile);
        ++i;
        if(i < upper)
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
        if(i >= lower)
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
    if(x < upper-1)
        i += 1;

    Tile* tile = board[y][i];

    while(i < upper && tile != nullptr) {
        checkConditions(placing, tile, diffColour, diffShape, sameTile);
        ++i;
        if(i < upper)
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
        if(i >= lower)
            tile = board[y][i];
    }

    return !((diffColour && diffShape) || sameTile);
}

void Board::checkConditions(Tile* placing, Tile* checking, bool& diffColour,
                            bool& diffShape, bool& sameTile) {
     
    if(*placing == *checking)               sameTile = true;
    if(placing->colour != checking->colour) diffColour = true; 
    if(placing->shape  != checking->shape)  diffShape = true;
}

Tile* Board::getAt(int x, int y) const {
    return board[y][x];
}

int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}
