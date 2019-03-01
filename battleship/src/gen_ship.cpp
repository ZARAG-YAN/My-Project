#include "gen_ship.hpp"
//The boats should be generated and arraanged so that they don/t have
//neighbors.The is_empty_array() function is a support function.

bool is_empty_array (char a[][10], int row, int col, int ship, int is_row_col)
{
    bool b = true;
    if (2 == is_row_col) {
        int t = col;
        col = row;
        row = t;
    }
     if (9 == row) {
        for (int i = row - 1; i <= row; ++i) {
            for (int j = col - 1; j < col + ship + 1; ++j) {
                if ( 2 == is_row_col && a[j][i] != '-') {
                    b = false;
                    break;
                } else if (1 == is_row_col && a[i][j] != '-') {
                    b = false;
                    break;
                }
            }
        }
    } else {
            for (int i = row - 1; i <= row + 1; ++i) {
                for (int j = col - 1; j < col + ship + 1; ++j) {
                    if ( 2 == is_row_col && a[j][i] != '-') {
                        b = false;
                        break;
                    } else if (1 == is_row_col && a[i][j] != '-') {
                        b = false;
                        break;
                    }
                }
            }
        }
        return b;
}


void gen_ships (char a[][10])
{
    srand (time(NULL));
    int ship = 4;
    int ship_count = 1; 
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < ship_count; ++j) {
            int row = rand() % 10;
            int col = rand() % 10;
            int is_row_col = rand() % 2 + 1;
            if (1 == is_row_col) {
              while ((10 - col) < ship || is_empty_array (a, row, col, ship, is_row_col) != true) {
                  row = rand() % 10;
                  col = rand() % 10;
              }
              for (int l = col; l < col + ship; ++l) {
                  a[row][l] = 'o';
              }
            } else if (2 == is_row_col){
               while ((10 - row) < ship || is_empty_array (a, row, col, ship, is_row_col) != true) {
                   row = rand() % 10;
                   col = rand() % 10;
              }    
              for (int l = row; l < row + ship; ++l) {
                  a[l][col] = 'o';
              }
           }
        }
        ++ship_count;
        --ship;
   }
}

