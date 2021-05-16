#include <iostream>
#include <fstream>
#include "Display.h"
#include "GameEngine.h"
#include "Parser.h"

#define EXIT_SUCCESS    0

GameEngine* load(std::string fileName);

int main(void) {
   int choice = -1;
   bool valid = true;
   bool quit = false;
   bool* quit_ptr = &quit;
   Display display = Display(quit_ptr);
   GameEngine* engine = nullptr;

   while(!quit) {

      if(valid)
         display.printMenu();

      choice = display.makeSelection();
      
      if(NEW_GAME == choice) {
         display.print("Enter player 1 name:");
         std::string player1Name = display.getInput();
         std::string player2Name;

         if(!quit) {
            display.print("Enter player 2 name:");
            player2Name = display.getInput();
         }
         
         if(!quit) {
            engine = new GameEngine(player1Name, player2Name);
            engine->start();
         }
         quit = true;
      }

      else if(LOAD_GAME == choice) {
         engine = load(display.getInput());
         engine->start();
      }

      else if(CREDITS == choice) {
         display.printCredits();
         do {
            std::string input = display.getInput();

            if(quit)
               choice = QUIT;
            else if(1 == input.length())
               choice = charToInt(input[0]);
         }
         while(choice != BACK && choice != QUIT);
         valid = true;
      }

      else
         valid = false;


      if(QUIT == choice)
         quit = true;
   }
   display.print("Goodbye!");
   if(nullptr != engine)
      delete engine;
   return EXIT_SUCCESS;
}



GameEngine* load(std::string filePath) {
   GameEngine* engine = nullptr;
   Parser::PlayerInfo_t player1Info;
   Parser::PlayerInfo_t player2Info;
   Parser::BoardState_t boardState;
   std::vector<std::string> tileBag;
   std::string currentPlayer;

   std::ifstream file(filePath);
   if(file) {
      player1Info = Parser::readPlayer(file);
      player2Info = Parser::readPlayer(file);
      boardState  = Parser::readBoard(file);
      tileBag = Parser::readCommaSeparatedList(file);
      getline(file, currentPlayer);

      engine = new GameEngine(player1Info, player2Info, boardState, tileBag, currentPlayer);
   } else
      std::cout << std::endl << "That file does not exist." << std::endl;

   return engine;

}

