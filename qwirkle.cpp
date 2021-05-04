
#include "LinkedList.h"
#include "Display.cpp"

#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   std::cout << "TODO: Implement Qwirkle!" << std::endl;
   std::string input;
   printMenu();
   getInput (input);
   makeSelection(input);

   return EXIT_SUCCESS;
}
