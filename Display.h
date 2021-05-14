
#ifndef ASSIGN2_DISPLAY_H
#define ASSIGN2_DISPLAY_H

#include <string>
#include <regex>
#include "Player.h"
#include "LinkedList.h"
#include "Board.h"
#include "Util.h"

#define NEW_GAME        1
#define LOAD_GAME       2
#define CREDITS         3
#define QUIT            4
#define BACK            5

class Display {
public:
    Display();
    Display(bool* quit);
    void printMenu();
    void printCredits();
    void print(Player& p);
    void print(Board& b);
    void print(std::string s);
    void prompt();
    std::string getInput();
    int makeSelection();
private:
   bool* quit;
};

#endif // ASSIGN2_DISPLAY_H