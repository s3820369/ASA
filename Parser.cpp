#include "Parser.h"
#include "Util.h"

Parser::PlayerInfo_t Parser::readPlayer(std::ifstream& file) {
    PlayerInfo_t playerInfo;

    std::string name, score, hand;
    std::vector<std::string> tiles = {};
    getline(file, playerInfo.name);
    getline(file, score);
    //getline(file, hand);

    playerInfo.hand = readCommaSeparatedList(file);
    playerInfo.score = stoi(score);
    return playerInfo;
}

std::vector<std::string> Parser::readCommaSeparatedList(std::ifstream& file) {
    std::string line;
    getline(file, line);
    
    std::vector<std::string> split = splitString(line, ",");

    return split;
}

Parser::BoardState_t Parser::readBoard(std::ifstream& file) {
    BoardState_t state;
    
    std::vector<std::string> dimensions = readCommaSeparatedList(file);
    std::string board;

    state.width  = stoi(dimensions[0]);
    state.height = stoi(dimensions[1]) + 'A' - 1;
    getline(file, board);


    std::stringstream inputStream(board);
    std::vector<std::string> splitBoard = splitString(board, " ");

 //   for(int i = 0; inputStream >> splitBoard[i]; ++i);
    state.unparsedBoard = splitBoard;

    return state;
}