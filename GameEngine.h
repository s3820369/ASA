
#ifndef ASSIGN2_GAMEENGINE_H
#define ASSIGN2_GAMEENGINE_H

#include <string>

#include "LinkedList.h"
#include "Display.h"
#include "Player.h"
#include "Board.h"

#define MAX_ARGS       4
#define PLACE        "place"
#define REPLACE     "replace"
#define SAVE         "save"
#define AT            "at"
#define NO_ERROR       ""
#define MAX_TILE_BAG_SIZE   72
class GameEngine {
public:
    void start();

private:
    std::string errorMessage;
    typedef struct Tokens_t
    {
        std::string command;
        std::string tileCode;
        std::string boardLoc;
        std::string saveFile;
    };

    Player* currentPlayer;
    Player player1;
    Player player2;
    LinkedList tileBag;
    Board board;
    Display display;
    Tokens_t tokens;

    bool parseInput(std::string input);
    bool validColour(char colour);
    bool validTile(std::string tileCode);
    bool validShape(int shape);
    bool validLoc(std::string location);
    bool executeCommand();
    bool gameIsOver();
    void checkError();
    bool save();
    void randomTileBag(Tile * tiles);
};

#endif // ASSIGN2_GAMEENGINE_H