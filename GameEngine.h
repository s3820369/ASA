
#ifndef ASSIGN2_GAMEENGINE_H
#define ASSIGN2_GAMEENGINE_H

#include <string>


#include "LinkedList.h"
#include "Display.h"
#include "Player.h"
#include "Board.h"
#include "Tile.h"
#include "TileCodes.h"

#define MAX_ARGS        4
#define PLACE        "place"
#define REPLACE     "replace"
#define SAVE         "save"
#define AT            "at"
#define NO_ERROR       ""

class GameEngine {
    public:
        GameEngine();
        GameEngine(std::string player1Name, std::string player2Name);
        ~GameEngine();
        void start();

    private:
        std::string errorMessage;
        
        // Parsed tokens of the command form stdandard in
        typedef struct
        {
            std::string command;
            std::string tileCode;
            std::string boardLoc;
            std::string saveFile;
        } Tokens_t;
        Tokens_t tokens;
        Display display;
        LinkedList tileBag;
        Player* currentPlayer;
        Player player1;
        Player player2;
        Board board;

        // Parse standard in command syntax. Checks bounds of board, valid command,
        // valid tile
        bool parseInput(std::string input);

        // Validate tile from input
        bool validTile(std::string tileCode);

        // Validate tile colour from input
        bool validColour(char colour);

        // Validate tile shape from input
        bool validShape(int shape);

        // Validate board location from input
        bool validLoc(std::string location);

        // Perform a valid command - place, replace, save
        bool executeCommand();

        // Checks end game condition
        bool gameIsOver();

        // Checks if error is set, prints
        void checkError();

        // Save game state to file
        bool save();


        std::vector<Tile*> createTile();
        void shuffleTiles(std::vector<Tile*> tiles);
        std::vector<Tile*> tilesState;
        void randomTileBag(Tile * tiles);
};

#endif // ASSIGN2_GAMEENGINE_H