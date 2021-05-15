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


int Board::calcScoreFrom(int col, int row, Tile* g) {
    // adding the points from the row
    // adding the points for columns
    //checking if sthers a qwirkle
    int i;
    //char row = y;
    //int rowDown = row - 'A';
   // int rowRight = abs(row - 'A');
    //char col = x;
    int scoreRowUp = 0;
    int scoreRowDown= 0;
    int scoreColRight = 0;
    int scoreColLeft= 0;
    bool stop = false;
    
    while(!stop){
        for(i = row;i<=BOARD_SIZE;i++){        
            
            if(board[i][col] != nullptr){
                scoreRowDown++;
            }else{
                stop = true;
            }
        }
    }
    stop = false;
    while(!stop){
        for(i = row;i<=0;i--){      //rowUp
            
                if(board[i][col] != nullptr){
                    scoreRowUp++;
                }else{
                    stop = true;
                }
            
        }
    }
    int totalRowScore = scoreRowDown + scoreRowUp - 1;   //change 1 with a define statement called duplicate
    stop = false;
    while(!stop){
        for(int g = col;g< BOARD_SIZE;g++){
            if(board[row][g] != nullptr){
                scoreColRight++;
            }else{
                stop = true;
            }
        }
    }
    stop = false;
    while (!stop)
    {
        for(int a = col;a<=0;a--){
            if(board[row][a] != nullptr){
                scoreColLeft++;
            }else{
                stop = true;
            }
        }
    }
    int totalColumnScore = scoreColLeft + scoreColRight - 1 ;   //change 1 with a define statement called duplicate
    int tot = totalRowScore + totalColumnScore;
    /**
     * if(totalRowScore || totalColumnScore){
     * std::cout<<"Qwirkle bois" << std::endl;
     *  }
     * 
    */

    return tot;


}



bool Board::legalPlacementAt(int x, int y, Tile* tile) {
    return isLegalVerticalCheck(tile, x, y, 0, ROWS)      &&
           isLegalHorizontalCheck(tile, x, y, 0, COLUMNS) &&
           nullptr == board[y][x];
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