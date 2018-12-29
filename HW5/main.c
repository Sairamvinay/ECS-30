#include "connectn.h"
/*
THIS FUNCTION READS THE NUMBER
OF ARGUMENTS AND CHECKS WHETHER IS IT FOUR OR NOT
*/

void readargs(int argc, char **argv, int *num_rows,int *num_columns,int *number_of_pieces_in_a_row_needed_to_win){

	if (argc < 4){

		printf("Not enough arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
	    exit(0);

	}

	else if (argc > 4){

		printf("Too many arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	
	}

	else{

		sscanf(argv[1],"%d",num_rows);
		sscanf(argv[2],"%d",num_columns);
		sscanf(argv[3],"%d",number_of_pieces_in_a_row_needed_to_win);
	}

}


/*
THIS FUNCTION CRETES ABOARD AND FILLS IT ALL WITH SPACES
*/
char **create_board(int num_rows, int num_columns){

	char **board = (char **) malloc(num_rows * sizeof(char *));
	int i,j;
	for (i=0;i<num_rows;i++){
		
		board[i] = (char *) malloc(num_columns * sizeof(char));
		for (j=0;j<num_columns;j++){

			board[i][j] = '*';
		} 
	}

	return board;
}


/*
THIS FUNCTION PRINTS THE BOARD AND DISPLAYS THE STATUS
OF THE GAME TO THE USER
*/
void print_board(char **board, int num_rows,int num_columns){

	int i,j;
	for (i=num_rows-1;i>=0;i--){
		printf("%d",i);
		for (j=0;j<num_columns;j++){
			printf(" %c",board[i][j]);
		}

		printf("\n");
	}

	printf("  "); // TO PRINT THE SPACE AFTER THE COLUMN NO AND ROW NO
	for (i=0;i<num_columns;i++){
		printf("%d ",i);
	}

	printf("\n");
}

/*
THIS FUNCTION SETS UP THE GAME BETWEEN PLAYER 1 AND PLAYER 2
*/ 
void setup_board(char ***board, int * turn, int num_rows,int num_columns){

	*board = create_board(num_rows,num_columns);
	*turn = 0;

}



/*
THIS FUNCTION CHECKS AND DECLARES WHETHER THE GAME
IS OVER OR NOT
*/

bool game_over(char **board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win){

	return (is_win(board,num_rows,num_columns,number_of_pieces_in_a_row_needed_to_win)) || 
	(is_tie(board,num_rows,num_columns,number_of_pieces_in_a_row_needed_to_win));

}


/*this function plays the game */
void play_game(char **board, int turn, int num_rows, int num_columns,int number_of_pieces_in_a_row_needed_to_win){

	int col=0;
	while (!game_over(board,num_rows,num_columns,number_of_pieces_in_a_row_needed_to_win)){

		print_board(board,num_rows,num_columns);
		prompt_user_and_move(board,num_rows,num_columns,col,turn);
		turn = (turn + 1) % 2;
	}

	print_board(board,num_rows,num_columns);
	declare_result(board,num_rows,num_columns,turn,number_of_pieces_in_a_row_needed_to_win);
}


/*this function deletes the memory created for the board*/
void destroy_board(char **board, int num_rows){

	int i;
	for (i=0;i<num_rows;i++){
		free(board[i]);
	}

	free(board);
}


/*
THIS FUNCTION PROMPTS THE USER FOR THE PIECE TO MOVE AND
THEN MAKES THE MOVE
*/
void prompt_user_and_move(char **board, int num_rows, int num_columns, int col,int turn){

	int row = 0;
	int num_args_read;
	do{

		printf("Enter a column between 0 and %d to play in: ",num_columns-1);
		num_args_read = scanf("%d",&col);
	
	} while(!play_is_valid(board,&row,col,num_rows,num_columns,num_args_read,1));


	if (turn == 0)
		board[row][col] = 'X' ;

	else
		board[row][col] = 'O';

}


//THIS FUNCTION CHECKS FOR THE VALID PLAY

bool play_is_valid(char **board, int *row, int col,int num_rows,int num_columns, int num_args_read,int num_args_reqd){

	if (num_args_read != num_args_reqd)
		return false;


	else if ((col < 0) || (col >= num_columns)){
		return false;
	} 

	else{

		while (board[*row][col] != '*'){
			*row+=1;
			if (*row == num_rows){
				*row -= num_rows;
				return false;
			}
		}
		char newline ='\n';
		do{
			scanf("%c",&newline);
			if (!isspace(newline)){
				return false;
			}
		}while (newline != '\n');
	
	}

	return true;
	
}


int main(int argc, char *argv[]){

	int num_rows,num_columns;
	int turn=0;
	int number_of_pieces_in_a_row_needed_to_win;
	char **board = NULL;


	readargs(argc,argv,&num_rows,&num_columns,&number_of_pieces_in_a_row_needed_to_win);
	setup_board(&board,&turn,num_rows,num_columns);
	play_game(board,turn,num_rows,num_columns,number_of_pieces_in_a_row_needed_to_win);
	destroy_board(board,num_rows);

	return 0;
}