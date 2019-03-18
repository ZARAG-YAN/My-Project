#include "is_dead.hpp"
#include "check_dir.hpp"
//checked if the boat disappeared.

bool is_dead (char a[][10], char player_board[][10], int row, int col)
{
   if (up(a, player_board, row, col)) {
    if (down(a, player_board, row, col)) {
     if (left(a, player_board, row, col)) {
      if ( right(a, player_board, row, col)) {
        return true;
       } else return false;
     } else return false;
    } else return false;
   } else return false;
}

