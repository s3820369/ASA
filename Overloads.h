#ifndef ASSIGN2_OVERLOADS_H
#define ASSIGN2_OVERLOADS_H

#include <fstream>
#include "Player.h"
#include "Tile.h"

std::ostream& operator<<(std::ostream &out, const LinkedList&  list) {
    for(int i = 0; i < list.size(); ++i) {
        out << list.at(i)->colour << list.at(i)->shape;
        if(i != list.size())
            out << ",";
    }
}

std::ostream& operator<<(std::ostream &out, const Player& player) {
    out << player.getName() << "\n" << player.getScore() << "\n"
        << player.getHandConst() << "\n";
}

#endif