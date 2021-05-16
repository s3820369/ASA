#ifndef ASSIGN2_PARSER_H
#define ASSIGN2_PARSER_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Parser {
    public:

        typedef struct
        {
            std::string name;
            int score;
            std::vector<std::string> hand;
        } PlayerInfo_t;

        typedef struct
        {
            int width;
            int height;
            std::vector<std::string> unparsedBoard;
        } BoardState_t;

        // Read lines from standard in and fill player info. Tiles are kept as
        // vector for Player to parse into whatever Hand implementation it has
        static PlayerInfo_t readPlayer(std::ifstream& file);

        // Read lines from standard in and fill BoardState. Tile@Pos will be kept
        // in vector for the Board itself to parse, to keep ADT functionality
        static BoardState_t readBoard(std::ifstream& file);

        static std::vector<std::string> readCommaSeparatedList(std::ifstream& file);
    private:
};


#endif