
#ifndef ASSIGN2_GAMEENGINE_H
#define ASSIGN2_GAMEENGINE_H

#include <Player.h>
#include <LinkedList.h>
#include <Board.h>
#include <string>

class GameEngine {
public:
    bool parseInput(std::string s);
    void makeMove();
    void start();

private:
    Player currentPlayer;
    Player player1;
    Player player2;
    LinkedList tileBag;
    Board board;
};

#endif // ASSIGN2_GAMEENGINE_H