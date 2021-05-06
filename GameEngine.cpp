
#include <iostream>
#include <fstream>
#include <sstream>
#include "Overloads.h"
#include "GameEngine.h"
#include "TileCodes.h"
#include <random>

GameEngine::~GameEngine() {
    // No deleting as nothing is allocated on the heap.
    // Can change if we're only allowed to new instances.
}

GameEngine::GameEngine() {
    display = Display();
    tileBag = LinkedList();
    board = Board();

    player1 = Player();
    player2 = Player();
    currentPlayer = &player1;
}


bool GameEngine::gameIsOver() {
    return (player1.getHand().size() == 0  || player2.getHand().size() == 0) &&
                                                        tileBag.size() == 0;
}

void GameEngine::checkError() {
    if(errorMessage != NO_ERROR) {
        display.print(errorMessage);
        errorMessage = NO_ERROR;
    }
}

void GameEngine::start() {
    std::string input = "";
    bool quit = false;

    while(!quit) {
        display.print(*currentPlayer);
        
        bool invalidInput = true;
        while(invalidInput) {

            if(getline(std::cin, input).eof()) {
                invalidInput = false;
                quit = true;
            }

            else if(parseInput(input)) {
                if(executeCommand())
                    invalidInput = false;
            } else
                errorMessage = "Please enter a valid command!";
            checkError();
        }
        currentPlayer = currentPlayer == player1 ? player2 : player1;
        
        if(gameIsOver())
            quit = true;
    }
    display.print("Goodbye!");
 }


bool GameEngine::executeCommand() {

    if(PLACE == tokens.command) {
        Tile* tile = currentPlayer->getTile(tokens.tileCode);

        if(nullptr != tile) {
            if(board.legalPlacementAt(tokens.boardLoc, tile))
                board.addToBoard(tile);
            else errorMessage = "You cannot place a tile here!";
        } else errorMessage = "You do not have that tile!";
    }

    else if(REPLACE == tokens.command) {
        Tile* playerTile = currentPlayer->getTile(tokens.tileCode);
        Tile* replacement = tileBag.pop_front();

        if(nullptr != playerTile) {
            if(nullptr != replacement)
                currentPlayer->replaceTile(playerTile, replacement);
            else errorMessage = "There are no more tiles in the bag!";
        } else errorMessage = "You do not have that tile!";
    }
    else if(tokens.command == SAVE) {
        save();
    }
}


bool GameEngine::parseInput(std::string input) {
    std::stringstream inputStream(input);
    std::string tokens[MAX_ARGS] = {};
    bool valid = false;

    for(int i = 0; i < MAX_ARGS && inputStream >> tokens[i]; ++i);

    if(tokens[0] == PLACE) {
        this->tokens.command = PLACE;

        if(validTile(tokens[1])) {

            if(tokens[2] == AT && validLoc(tokens[3])) {
                this->tokens.boardLoc = tokens[3];
                valid = true;
            }
        }
    }

    else if(tokens[0] == REPLACE) {
        if(validTile(tokens[1]))
            this->tokens.tileCode = tokens[1];
    }
    
    else if(tokens[0] == SAVE) {
        this->tokens.saveFile = tokens[1];
    }
}

bool GameEngine::validTile(std::string tileCode) {
    bool valid = true;
    const char* tile = tileCode.c_str();

    if(tileCode.length() == 2) {
        if(validColour(tile[0]) && validShape(tile[1] - '0'))
            tokens.tileCode = tileCode;
    }
    return valid;
}

bool GameEngine::validLoc(std::string location) {
    bool validRow = false;
    bool validCol = false;

    const char* loc = location.c_str();

    if(loc[0] > 'A' && loc[0] < board.getMaxRow())
        validRow = true;

    if(loc[1] > 0 && loc[1] < board.getMaxCol())
        validCol = true;

    return validRow && validCol;
}

bool GameEngine::validColour(char c) {
    bool valid = true;

    if     (c == RED);
    else if(c == ORANGE);
    else if(c == YELLOW);
    else if(c == GREEN);
    else if(c == BLUE);
    else if(c == PURPLE);
    else    valid = false;

    return valid;
}

bool GameEngine::validShape(int shape) {
    bool valid = true;

    if     (shape == CIRCLE);
    else if(shape == STAR_4);
    else if(shape == DIAMOND);
    else if(shape == SQUARE);
    else if(shape == STAR_6);
    else if(shape == CLOVER);
    else    valid = false;

    return valid;
}

bool GameEngine::save() {
    std::ofstream outputFile("./" + tokens.saveFile + ".save");

    if(outputFile.good()) {
        outputFile << player1; 
        outputFile << player2;
//        outputFile << board;    // TODO
        outputFile << tileBag;
        outputFile << currentPlayer->getName();
    }
}

void randomTileBag(Tile * tiles){
    int max = 72;
    LinkedList tileBag;
    std::random_device randomSeed;
    std::uniform_int_distribution<int> uniform_dist(0, max-1);
    int i = 0;
    //loop throught the whole tile size
    while(i< MAX_TILE_BAG_SIZE){
        int randIndex = uniform_dist(randomSeed);
        //check if at random pos there is tile or not if not add it to the bag.
        if(tileBag.at(randIndex) != nullptr){
            tileBag.insert(randIndex, tiles);
            ++i;
        }
    }
}