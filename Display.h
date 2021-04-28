
#ifndef ASSIGN2_DISPLAY_H
#define ASSIGN2_DISPLAY_H

#include <Player.h>
#include <LinkedList.h>
#include <Board.h>
#include <string>

class Display {
public:
    void printMenu();
    void printCredits();
    void print(Player p);
    void print(Board b);
    void print(std::string s);

private:
   
};

#endif // ASSIGN2_DISPLAY_H