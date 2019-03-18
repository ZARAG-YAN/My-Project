#include <iostream>
#include "brief.hpp"
//Some info about holding the "Battleship" games.
void brief_game()
{   
    std::cout << " \t*****************************************\n";
    std::cout << " \t*\tWelcome 'Battleship' game     \t*\n";
    std::cout << " \t*****************************************\n\n";
    std::cout << "-- The game will be held between the computer and the user.\n";
    std::cout << "-- If you want to start the game input 'start'.\n";
    std::cout << "-- Enter your shot (ex. 2.3 or 2 3 or 2/3).\n";
    std::cout << "-- The shooting boat is marked with 'x'.\n";
    std::cout << "-- Already mentioned and missed coordinates are indicated by '*' \n";
    std::cout << "-- If you want to show generated board input 'show'.\n";
    std::cout << "-- If you want to leave the game input 'exit' or 'quit'.\n";
    std::cout << "-- For more information write 'help'\n\n";
}    
