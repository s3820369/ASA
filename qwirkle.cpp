#include <iostream>
#include "Display.h"
#include "GameEngine.h"

#define EXIT_SUCCESS    0


int main(void) {
   int choice = -1;
   bool valid = true;
   bool quit = false;
   bool* quit_ptr = &quit;
   Display display = Display(quit_ptr);

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
         if(!quit)
            GameEngine(player1Name, player2Name).start();
         quit = true;
      }
      else if(LOAD_GAME == choice) {
         // TODO
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

   return EXIT_SUCCESS;
}

