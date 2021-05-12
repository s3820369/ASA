#include <iostream>
#include <stdexcept>
#include<Board.h>
#include<TileCodes.h>
// ill have positions 
char i;
int j = 0;


Board::Board(){
    width = BOARD_SIZE;
    height = BOARD_SIZE;
    this->board.resize(BOARD_SIZE);
    for ( int g = 0; g < 26; g++ ) {
        this->board[i] = std::vector<Tile*>(BOARD_SIZE);
        for ( int k = 0; k < 26; k++ ){
            this->board[i][j] = nullptr;
        }
    }

}

void Board::addToBoard(Tile* t,std::string pos){
   
    char Row = pos[0];
    char Col = pos[1];
    int row = 'Z' - Row;
    int ColNum = Col - '0';
    // take the position of the tile. and say that position as the tile
    this->board[row][ColNum] = new Tile(*t);
}


int Board::calcScoreFrom(std::string pos, Tile* g){
    // adding the points from the row
    // adding the points for columns
    //checking if thers a qwirkle
    
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


}


bool Board::legalPlacementAt(std::string pos, Tile* t){
    char rowString = pos[0];
    int row = 'Z' - rowString;
    char colString = pos[1];
    int col = colString - '0';
   
    
    bool v = islegalVerticalCheck(col,row,t);
    bool h = islegalHorizontalCheck(col,row,t);
   
    return (islegalVerticalCheck && islegalHorizontalCheck) ;

    
}

std::vector<std::vector<Tile*>> Board::getBoard(){
    return board;
}

int Board::getWidth(){
    return width;

}
int Board::getHeight(){
    return height;
}

bool Board::islegalVerticalCheck(int x,int y,Tile* t) {
    bool differentShape;
    bool differentColor ;
    bool sameTile = false;
    int d = y+1;
    Tile* tile = board[d][x];
    while (d < 26 && tile != nullptr) {
        if (tile->colour == t->colour && tile->shape == t->shape){
            sameTile = true;
        }
        if(tile->colour != t->colour){
            differentColor = true;    
        }
         if(tile->shape != t->shape){
            differentShape = true;
        }
        tile = board[++d][x];
    }
    d = y -1;
    tile = board[d][x];
    while (d >= 0 && tile != nullptr) {
        if (tile->colour == t->colour && tile->shape == t->shape){
            sameTile = true;
        }
        if(tile->colour != t->colour){
            differentColor = true;    
        }
         if(tile->shape != t->shape){
            differentShape = true;
        }
        tile = board[--d][x];
    return !(differentShape && differentColor || sameTile);
    }
}
bool Board::islegalHorizontalCheck(int x,int y,Tile* t){
    bool differentShape;
    bool differentColor ;
    bool sameTile = false;
    int height = 26;
    int d = x+1;
    Tile* tile = board[y][d];
    while (d < 26 && tile != nullptr) {
        if (tile->colour == t->colour && tile->shape == t->shape){
            sameTile = true;           // false
        }
        if(tile->colour != t->colour){
            differentColor = true;    // this becomes true
        }
         if(tile->shape != t->shape){
            differentShape = true;        // false
        }
        tile = board[y][d++];
    }
    d = y -1;
    tile = board[d][x];
    while (d >= 0 && tile != nullptr) {
        if (tile->colour == t->colour && tile->shape == t->shape){
             sameTile = true;
         }
        if(tile->colour != t->colour){
         differentColor = true;    
         }
         if(tile->shape != t->shape){
             differentShape = true;
         }
        tile = board[y][--d];
    }
    return !(differentShape && differentColor || sameTile);     

}
void Board::displayBoard(){
    char alphabets = 'A';
    for(int y = 0; y<BOARD_SIZE; y++){
        if(y == 0){
            for (int u = 0; u< BOARD_SIZE; u++){
                if(u == 0){
                    std::cout<<"  ";
                }
                if(u <= 25){
                    std::cout << u << "  ";
                }
            }
            std::cout << std::endl;
            std::cout << "--------------------------------------"<< std::endl ;
        }
        for (int c = 0; c<BOARD_SIZE; c++){
            if(c == 0 ){
                std::cout << alphabets << "|";
                alphabets++;
            }
            if(this->board[y][c] == nullptr){
                std::cout << "  |";
            }else{
                std::cout << this->board[y][c]->colour << this->board[y][c]->shape<<"|";
            }
        }
        std::cout<<std::endl;
    }
}
