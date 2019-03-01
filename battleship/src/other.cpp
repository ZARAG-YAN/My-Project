#include <iostream>
#include "other.hpp"

void other (std::string s, char a[][10])
{
    if (s == "help") {
        help();
    }   
    if (s == "show") {
        show_board (a);    
    }   
    if (s == "start"){
        std::cout<< "\t**** The game started ****\n";
    }   
    if (s == "exit" || s == "quit"){
       std::cout<<"You left the game ...\n";
       _Exit(s[0]);
    }   
}

void help ()
{
    std::cout << "\n\t--help\n\n";
    std::cout << "\t- The game will be held between the computer and the user.\n";
    std::cout << "\t- The computer will generate a map of  1 - 4 size boats, and\n";
    std::cout << "\t  the user must properly shot and destroy the boats. \n";
    std::cout << "\t- There are 4 pieces of 1 long boats.            \n";
    std::cout << "\t            3 pieces of 2 long boats.            \n";
    std::cout << "\t            2 pieces of 3 long boats.            \n";
    std::cout << "\t            1 pieces of 4 long boats.            \n";
    std::cout << "\t- Already mentioned and missed coordinates are indicated by '*'. \n";
    std::cout << "\t- The shooting boat is marked with 'x'.\n";
    std::cout << "\t- If you want to show generated board input 'show'.\n";
    std::cout << "\t- If you want to leave the game input 'exit' or 'quit'.\n";
    std::cout << "\t- Enter your shot (ex. 2.3 or 2 3 or 2/3).\n\n";
}



void show_board (char arr[][10])
{
    std::cout<<"\n  ";
    for (int i = 0; i < 10; ++i){
        std::cout << i <<" ";
    } std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j == 0) std::cout << i <<" ";
            std::cout << arr[i][j] <<" ";
        } std::cout << std::endl;
    } std::cout << std::endl;
}

