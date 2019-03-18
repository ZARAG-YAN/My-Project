#include <iostream>
#include "check_dir.hpp"
// This file includes the following 4 functions, that get generated and user
// dumps,imported coordinates as arguments.Checks the surrounding area of the user's boat.


bool up(char a[][10], char player_board[][10], int row, const int& col)
{  
    row -= 1;
    while (a[row][col] == 'o' && row >= 0) {
        if (player_board[row][col] == 'x') {
            --row;
        } else {
            return false;
        }
    }
    return true;
}

bool down(char a[][10], char player_board[][10], int row, const int& col)
{  
    row += 1;
    while (a[row][col] == 'o' && row <= 9) {
        if (player_board[row][col] == 'x') {
            ++row;
        } else {
            return false;
        }   
    }   
    return true;
}
bool left(char a[][10], char player_board[][10], const int& row, int col)
{
    col -= 1;
    while (a[row][col] == 'o' && col >= 0) {
        if (player_board[row][col] == 'x') {
            --col;
        } else {
            return false;
        }
    }
    return true;
}

bool right(char a[][10], char player_board[][10], const int& row, int col)
{
    col += 1;
    while (a[row][col] == 'o' && col <= 9) {
        if (player_board[row][col] == 'x') {
            ++col;
        } else {
            return false;
        }
    }
    return true;
}

