#ifndef CONNECTN_H
   #define CONNECTN_H
   #include <stdio.h>
   #include <stdlib.h>
   #include <stdbool.h>
   #include <ctype.h>
   void setup_board(char ***board, int * turn, int num_rows,int num_columns);
   void play_game(char **board, int turn, int num_rows, int num_columns,int number_of_pieces_in_a_row_needed_to_win);
   void readargs(int argc, char **argv, int *num_rows,int *num_columns,int *number_of_pieces_in_a_row_needed_to_win);
   char **create_board(int num_rows, int num_columns);
   void print_board(char **board, int num_rows,int num_columns);
   bool play_is_valid(char **board, int *row, int col,int num_rows,int num_columns,int num_args_read,int num_args_reqd);
   void prompt_user_and_move(char **board, int num_rows, int num_columns, int col,int turn);
   void destroy_board(char **board, int num_rows);
   bool game_over(char **board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win);
   bool is_win(char **board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win);
   bool is_horz_win(char **board, int num_rows,int num_columns, int number_of_pieces_in_a_row_needed_to_win);
   bool is_vert_win(char **board,int num_rows,int num_columns, int number_of_pieces_in_a_row_needed_to_win);
   bool is_diag_win(char **board, int num_rows,int num_columns, int number_of_pieces_in_a_row_needed_to_win);
   bool is_left_diag_win(char **board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win);
   bool is_right_diag_win(char **board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win);
   bool is_board_full(char **board,int num_rows, int num_columns);
   bool is_tie(char **board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win);
   void declare_result(char **board, int num_rows,int num_columns,int turn, int number_of_pieces_in_a_row_needed_to_win);
   


#endif