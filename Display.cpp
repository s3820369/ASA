#include <iostream>
#include "Display.h"

Display::Display() {}
Display::Display(bool* quit) : quit(quit) {}

void Display::printMenu() {
    std::cout << "Welcome to Qwirkle"   << std::endl;
    std::cout << "----"                 << std::endl;
    std::cout << "Menu"                 << std::endl;
    std::cout << "----"                 << std::endl;
    std::cout << "1. New Game"          << std::endl;
    std::cout << "2. Load Game"         << std::endl;
    std::cout << "3. Credits"           << std::endl;
    std::cout << "4. Quit"              << std::endl;
}

void Display::printCredits() {
    std::cout << "------------------------"                 << std::endl;
    std::cout << "Name: Abu Kuhafah"                        << std::endl;
    std::cout << "Student ID: s3839222"                     << std::endl;
    std::cout << "Email: s3839222@student.rmit.edu.au"      << std::endl;
    std::cout <<                                               std::endl;
    std::cout << "Name: Alasdair Moloney"                   << std::endl;
    std::cout << "Student ID: s3785526"                     << std::endl;
    std::cout << "Email: s3785526@student.rmit.edu.au"      << std::endl;
    std::cout <<                                               std::endl;
    std::cout << "Name: Hibbaan Mohammed Nawaz"             << std::endl;
    std::cout << "Student ID: s3847243"                     << std::endl;
    std::cout << "Email: s3847243@student.rmit.edu.au"      << std::endl;
    std::cout <<                                               std::endl;
    std::cout << "Name: Sithira Deelaka Hikkaduwa Liyanage" << std::endl;
    std::cout << "Student ID: s3820369"                     << std::endl;
    std::cout << "Email: s3820369@student.rmit.edu.au"      << std::endl;
    std::cout << "------------------------"                 << std::endl;
    std::cout <<                                               std::endl;
    std::cout << "5. back"                                  << std::endl;
}

std::string Display::getInput() {
    std::string input;

    while(!*quit && !std::regex_match(input, std::regex("\\w+"))) {
        std::cout << "> ";

        if(std::getline(std::cin, input).eof()) {
            *quit = true;
            input = QUIT;
        }
    }
    std::cout << std::endl;
    return input;
}

int Display::makeSelection() {
    bool selectionDone = true;
    std::string input = "";

    do {
        input = getInput();

        if(quit);
        else if(input.length() == 1) {
            if     (charToInt(input[0]) == NEW_GAME);
            else if(charToInt(input[0]) == LOAD_GAME);
            else if(charToInt(input[0]) == CREDITS);
            else if(charToInt(input[0]) == QUIT);
            else if(charToInt(input[0]) == BACK);
            else selectionDone = false;
        }
        
        if(!selectionDone)
            print("Please select a valid option.");

   } while(!selectionDone);
   return charToInt(input[0]);
}

void Display::print(std::string s) {
   std::cout << s << std::endl;
}

void Display::print(Player& player) {
   std::cout << "Player: " + player.getName() + "\n"
             << player.getScore() << "\n"
             << player.getHand() << std::endl;
}

std::ostream& operator<<(std::ostream &out, const LinkedList& list) {
    for(int i = 0; i < list.size(); ++i) {
        out << list.at(i)->colour << list.at(i)->shape;
        if(i != list.size()-1)
            out << ",";
    }
    out << std::endl;
    return out;
}

std::ostream& operator<<(std::ostream &out, const Player& player) {
    out << player.getName() << '\n' << std::to_string(player.getScore())
        << '\n' << player.getHandConst();
    return out;
}