#include <iostream>

// board (hibbaan), tilebag(ABU), points , shifitn between players(Al) , having a continous loop of the game(Al)
void printMenu(){
   std::cout << "Welcome to Qwirkle" <<std::endl;
   std::cout << "----" <<std::endl;

   std::cout << "Menu" <<std::endl;
   std::cout << "----" <<std::endl;
   std::cout << "1. New Game" <<std::endl;
   std::cout << "2. Load Game" <<std::endl;
   std::cout << "3. Credits" <<std::endl;
   std::cout << "4. Quit" <<std::endl;
}

void printCredits(){
   std::cout << "------------------------" <<std::endl;
   
   std::cout << "Name: Abu Kuhafah" <<std::endl;
   std::cout << "Student ID: s3839222" <<std::endl;
   std::cout << "Email: s3839222@student.rmit.edu.au" <<std::endl;
   
   std::cout << "Name: Alasdair Moloney" <<std::endl;
   std::cout << "Student ID: s3785526" <<std::endl;
   std::cout << "Email: s3785526@student.rmit.edu.au" <<std::endl;

   std::cout << "Name: Hibbaan Mohammed Nawaz" <<std::endl;
   std::cout << "Student ID: s3847243" <<std::endl;
   std::cout << "Email: s3847243@student.rmit.edu.au" <<std::endl;
   
   std::cout << "Name: Sithira Deelaka Hikkaduwa Liyanage" <<std::endl;
   std::cout << "Student ID: s3820369" <<std::endl;
   std::cout << "Email: s3820369@student.rmit.edu.au" <<std::endl;
   std::cout << "------------------------" <<std::endl;
}
void getInput(std::string &input){
   std::cout << ">";
   std::getline(std::cin,input);

}
void makeSelection(std::string input){
   bool selectionDone = false;
   while(!selectionDone){
      if(input == "1" || input == "2" || input == "3" || input == "4"){
         if(input.compare("1") == 0){
            std::cout << "New Game selected{for testing purposes}" << std::endl;
            selectionDone = true;

         }
          else if(input.compare("2") == 0){
            std::cout << "Load Game selected{for testing purposes}" << std::endl;
            selectionDone = true;

         }
          else if(input.compare("3") == 0){
            std::cout << "Credits selected{for testing purposes}" << std::endl;
            printCredits();
            selectionDone = true;

         } else if(input.compare("4") == 0){
            std::cout << "Quit selected{for testing purposes}" << std::endl;
            selectionDone = true;

         }
      }else{
         std::cout <<"Number entered not in the range" << std::endl;
      }
   }
}