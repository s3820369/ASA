
#include "LinkedList.h"

#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   std::cout << "TODO: Implement Qwirkle!" << std::endl;

   return EXIT_SUCCESS;
}

void menu(){
   std::cout << "Menu" <<std::endl;
   std::cout << "----" <<std::endl;
   std::cout << "1. New Game" <<std::endl;
   std::cout << "2. Load Game" <<std::endl;
   std::cout << "3. Credits" <<std::endl;
   std::cout << "4. Quit" <<std::endl;
}

void credits(){
   std::cout << "------------------------" <<std::endl;
   
   std::cout << "Name: Abu Kuhafah" <<std::endl;
   std::cout << "Student ID: s3839222" <<std::endl;
   std::cout << "Email: s3839222@student.rmit.edu.au" <<std::endl;

   std::cout << "Name: Sithira Deelaka Hikkaduwa Liyanage" <<std::endl;
   std::cout << "Student ID: s3820369" <<std::endl;
   std::cout << "Email: s3820369@student.rmit.edu.au" <<std::endl;

   std::cout << "Name: Alasdair Moloney" <<std::endl;
   std::cout << "Student ID: s3785526" <<std::endl;
   std::cout << "Email: s3785526@student.rmit.edu.au" <<std::endl;



   std::cout << "------------------------" <<std::endl;
}