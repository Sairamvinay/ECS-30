#include "connectn.h"


/*
THIS FUNCTION CHECKS WHETHER THE MATCH IS WON 
*/
bool is_win(char **board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win){

	return is_horz_win(board,num_rows,num_columns,number_of_pieces_in_a_row_needed_to_win) || 
	(is_vert_win(board,num_rows,num_columns,number_of_pieces_in_a_row_needed_to_win)) ||
	is_diag_win(board,num_rows,num_columns,number_of_pieces_in_a_row_needed_to_win);
}

/*
THIS FUNCTION CHECKS WHETHER IS IT A HORIZONTAL WIN IE
THE ROW IS FILLED WITH N CONSECUTIVE SAME PIECES
*/
bool is_horz_win(char **board, int num_rows,int num_columns, int number_of_pieces_in_a_row_needed_to_win){

	int i,j;
	char init_piece;
	int no_of_same_pieces;
	for (i=0;i<num_rows;i++){
		init_piece = board[i][0];
		no_of_same_pieces =1;
		for (j=1; j<num_columns;j++){
			if (board[i][j] == init_piece)
				no_of_same_pieces++;

			else{
				init_piece = board[i][j];
				no_of_same_pieces=1;
			}

			if ((no_of_same_pieces >= number_of_pieces_in_a_row_needed_to_win) && (init_piece!='*')){
				return true;
			}
		}
	}

	return false;	
}

/*
THIS FUNCTION CHECKS WHETHER THE WIN IS 
COLUMN WISE OR NOT IE VERTICAL WIN
*/
bool is_vert_win(char **board,int num_rows,int num_columns,int number_of_pieces_in_a_row_needed_to_win){

	int i,j,no_of_same_pieces;
	char init_piece;
	for (i=0;i<num_columns;i++){
		
		no_of_same_pieces=1;
		init_piece = board[0][i];
		
		for (j=1; j<num_rows;j++){

			if (board[j][i] == init_piece){
				no_of_same_pieces++;
			}

			else{

				init_piece = board[j][i];
				no_of_same_pieces =1;
			}

			if (no_of_same_pieces >= number_of_pieces_in_a_row_needed_to_win  && init_piece!='*'){
				return true;
			}
		}
	}
	
	return false;
}


/*
THIS FUNCTION CHECKS WHETHER THE WIN IS DIAGONAL
OR NOT
*/
bool is_diag_win(char **board, int num_rows, int num_columns,int number_of_pieces_in_a_row_needed_to_win){

	return (is_right_diag_win(board,num_rows,num_columns,number_of_pieces_in_a_row_needed_to_win)
	|| is_left_diag_win(board,num_rows,num_columns,number_of_pieces_in_a_row_needed_to_win));
}



/*
THIS FUNCTION CHECKS FOR A WIN LEFT DIAGONALLY
*/
bool is_left_diag_win(char **board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win){

	int i,no_of_same_pieces;
	int x_coord, y_coord;
	//i represents the diagonal number
	for (i=0;i<(num_rows+num_columns-1);i++){

		x_coord = (0>(i- num_rows + 1))? 0 : (i - num_rows + 1);
		y_coord = (0>( num_rows - 1 -i)) ? 0 : (num_rows - 1 - i);
		char init_piece = board[y_coord][x_coord];
		no_of_same_pieces = 1;
		x_coord++;
		y_coord++;
		while ((x_coord < num_columns) &&  (y_coord< num_rows)){

			if (board[y_coord][x_coord] == init_piece){
				no_of_same_pieces++;
			}

			else{
				init_piece = board[y_coord][x_coord];
				no_of_same_pieces = 1;
			}

			if ((no_of_same_pieces >= number_of_pieces_in_a_row_needed_to_win)  && (init_piece!='*')){
				return true;
			}
			x_coord++;
			y_coord++;
			
		}

	}

	return false;
}

/*
THIS FUNCTION CHECKS FOR A WIN RIGHT DIAGONALLY
*/
bool is_right_diag_win(char **board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win){

	int i,no_of_same_pieces;
	char init_piece;
	for(i=0 ; i<(num_rows + num_columns - 1) ; i++){

		int x_coord, y_coord;
		x_coord = (i > (num_columns-1)) ? (num_columns-1): i;
		y_coord = (0> (i - (num_columns-1))) ? 0 : i-(num_columns-1);
		init_piece = board[y_coord][x_coord];
		no_of_same_pieces = 1;
		x_coord--;
		y_coord++;
		while ((x_coord>=0) && (y_coord<num_rows)){

			if (board[y_coord][x_coord] == init_piece)
				no_of_same_pieces++;

			else{

				init_piece = board[y_coord][x_coord];
				no_of_same_pieces = 1;
			}

			if (no_of_same_pieces >= number_of_pieces_in_a_row_needed_to_win  && init_piece!='*'){
				return true;
			}

			x_coord--;
			y_coord++;
		}
	}
		
	return false;
}




/*THIS FUNCTION CHECKS WHETHER THE 
GAME IS TIED
*/
bool is_tie(char **board,int num_rows,int num_columns,int number_of_pieces_in_a_row_needed_to_win){

	return (is_board_full(board,num_rows,num_columns) && (!is_win(board,num_rows,num_columns,number_of_pieces_in_a_row_needed_to_win)));

}


/*
THIS FUNCTION CHECKS WHETHER THE BOARD IS FULL OR NOT
*/
bool is_board_full(char **board, int num_rows,int num_columns){

	int i,j;
	for (i=0;i<num_rows;i++){

		for (j=0;j<num_columns;j++){

			if (board[i][j] == '*'){
				return false;
			}
		}
	}
	return true;
}


/* THIS FUNCTION DECLARES THE WINNER*/
void declare_result(char **board, int num_rows,int num_columns,int turn, int number_of_pieces_in_a_row_needed_to_win){

	if (is_tie(board,num_rows,num_columns,number_of_pieces_in_a_row_needed_to_win))
		printf("Tie game!");

	else if (turn == 0)
		printf("Player 2 Won!");

	else
		printf("Player 1 Won!");
}


