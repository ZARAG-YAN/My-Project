#include <iostream>
#include "run.hpp"
#include "other.hpp"
#include "gen_ship.hpp"
#include "is_dead.hpp"

bool user_input(int& row, int& col, char rand_b[][10])
{
    std::string str("");
    do {
          getline(std::cin, str);
          other(str, rand_b);
          if (str.size() != 3) {
              std::cout << "Please input two numbers ." << std::endl;
          } else if (str[0] < '0'|| str[0] > '9'|| str[2] < '0'|| str[2] > '9'|| str == " ") {
              std::cout << "Please input number between 0 and 9." << std::endl;
          } else if (str[1] == '.'|| str[1] == ' '|| str[1] == '/' ) {
              std::stringstream zaa;
              zaa << str[0];
              zaa >> row;
              std::stringstream baa;
              baa << str[2];
              baa >> col;
          } else {
              std::cout << "Please enter shot as follows: 2.3 or 2 3 or 2/3";
          }
     } while (!true);
     return true;
}


void start(char play_b[][10],char rand_b[][10], int& row, int& col )
{
    int x_count = 0;
    std::string str("");
    while (str != "start") {
        getline(std::cin, str);
    }
    other(str,rand_b);
    while (user_input (row, col, rand_b)) {
        if (rand_b[row][col] == '-') {
             if (play_b[row][col] == '*') {
                 std::cout << "Duplicate value.\n";
             } else {
                 play_b[row][col] = '*';
                 std::cout << "You missed!\n";
               }
        } else {
                 ++x_count;
                 play_b[row][col] = 'x';
                 if (is_dead (rand_b, play_b, row, col)) {
                    std::cout << "The boat is destroyed ..." << std::endl;
                 } else {
                    std::cout << "The boat is wonted ...\n Continue to shoot.\n";
                 }
          }
          show_board (play_b);
          if ( 20 == x_count ) {
              std::cout << "User win!!! "<<std::endl;
             _Exit(x_count);
          }
          std::cout << "Enter your shot >>>  ";
    }
}

void run()
{
    int row = 0;
    int col = 0;
    char rand_board[10][10] = {};
    char player_board[10][10] = {};

    for (int i = 0; i < 10; ++i) {
        for (int  j = 0; j <= 10; ++j) {
            rand_board[i][j] = '-';
            player_board[i][j] = '-';
        }
    }
    gen_ships(rand_board);
    start(player_board, rand_board, row, col);
}
