#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/*
THIS FUNCTION CHECKS WHETHER THE INPUT PROVIDED
IS VALID OR NOT IF NOT THEN IT RETURNS 
FALSE OR ELSE RETURNS TRUE. ALSO CHECKS
FOR THE SPACES AFTER THE VALID INPUT GIVEN WHETHER
IS IT ONLY SPACE OR NOT
*/
bool is_valid_formatting (int num_args_read , int num_args_reqd){

	char newline = '\n';
	bool is_valid = true;
    if (num_args_read != num_args_reqd){

    	is_valid = false;
    }


    do{
    	scanf("%c",&newline);
    	if (!isspace(newline)){
    		is_valid = false;
    	}
    
    } while (newline != '\n');

    return is_valid;
}



/* THIS FUNCTION KEEPS PROMPTING USER FOR
A SEED TILL THE USERS ENTERS A VALID INPUT
CALLS IS_VALID_FORMATTING FOR CHECKING THE VALIDATION
OF THE INPUT
*/

int get_valid_seed(){

	int seed,num_args_read;
	do{
		printf("Enter the seed for the random number generator: ");
		num_args_read = scanf("%d",&seed);
	
	}while (!is_valid_formatting(num_args_read,1));

	return seed;
}


/* THIS FUNCTION CHECKS WHETHER THE ROW VALUE
IS VALID AND A POSITIVE WHOLE NUMBER
*/

int get_valid_row(){
    
    int row,num_args_read;
    do{
        printf("Enter the number of rows on the board: ");
        num_args_read = scanf("%d",&row);

    } while (!is_valid_formatting(num_args_read,1) || (row <= 0) );
    
    return row;
}


/* THIS FUNCTION CHECKS WHETHER THE COLUMN VALUE
IS VALID AND A POSITIVE WHOLE NUMBER
*/

int get_valid_col(){
    
    int col,num_args_read;
    do{
        printf("Enter the number of columns on the board: ");
        num_args_read = scanf("%d",&col);

    } while (!is_valid_formatting(num_args_read,1) || (col <= 0) );
    
    return col;
}


/* THIS FUNCTION CHECKS WHETHER THE NUMBER OF ROUNDS VALUE
IS VALID AND A POSITIVE WHOLE NUMBER
*/

int get_valid_no_of_trials(){
    
    int no_of_trials,num_args_read;
    do{
        printf("Enter the number of simulations to run: ");
        num_args_read = scanf("%d",&no_of_trials);

    } while (!is_valid_formatting(num_args_read,1) || (no_of_trials <= 0) );
    
    return no_of_trials;
}


//THIS FUNCTION GENERARTES A RANDOM INTEGER BETWEEN LOW AND HIGH
int rand_int(int low, int high){

    return low + (rand() % (high - low + 1));

}


/*
THIS FUNCTION KEEPS CHANGING THE POSITION
OF THE PIECES AND RETURNS THE PIECE'S POSITION 
BY REFERENCE
*/
int change_piece_pos(int movepiecedim, int statpiecedim){
    int diff_dim = abs(movepiecedim - statpiecedim);
    if (movepiecedim > statpiecedim){
        
        movepiecedim -= rand_int(0,diff_dim);
    }

    else if (movepiecedim < statpiecedim){

        movepiecedim += rand_int(0,diff_dim);
    }

    
    return movepiecedim;
}    
    

void printsimulation(int old_r1 ,int old_c1, int old_r2, int old_c2, int piece1row , int piece1col , int piece2row , int piece2col){
    
    printf("First piece moves from %d,%d to %d,%d\n", old_r1 , old_c1, piece1row , piece1col);
    printf("Second piece moves from %d,%d to %d,%d\n",old_r2,old_c2,piece2row,piece2col);
}

/*
THIS FUNCTION CALCULATES AND RETURNS 
THE NUMBER OF ROUNDS IT TAKES FOR THE
TWO PIECES TO MEET UP
ALSO CALLS THE RAND_GEN_FOR_PIECES FUNCTION
TO GENERATE RANDOM VALUES FOR PIECES
*/

int one_trial_meet_up(int row , int col , int no_of_trials){
    
    int no_of_rounds = 0;

    int piece1row , piece1col;
    int piece2row , piece2col;
    
    piece1row = rand_int(0 , row-1);
    piece1col = rand_int(0 , col-1);
    piece2row = rand_int(0 , row-1);
    piece2col = rand_int(0 , col-1);
    
    if (no_of_trials <= 5){
        printf("Piece one starts at: %d, %d\n" , piece1row , piece1col);
        printf("Piece two starts at: %d, %d\n", piece2row , piece2col);
    }

    while (!((piece1row == piece2row) && (piece1col == piece2col))){
        no_of_rounds++;
        int old_r1 ,old_c1,old_r2,old_c2;
        old_r1 = piece1row;
        old_r2 = piece2row;
        old_c1 = piece1col;
        old_c2 = piece2col;

        piece1row = change_piece_pos(piece1row , piece2row);
        piece1col = change_piece_pos(piece1col , piece2col);
        piece2row = change_piece_pos(piece2row , old_r1);
        piece2col = change_piece_pos(piece2col , old_c1);

        if (no_of_trials <= 5 ){

            printsimulation(old_r1 , old_c1 ,old_r2,old_c2,piece1row,piece1col,piece2row,piece2col);
        
        }
        
        else{
            
            //EMPTY BLOCK AS NOTHING REQUIRED.
        }  
    } 

    return no_of_rounds;

}

/*
THIS FUNCTION KEEPS SIMULATING THE NUMBER OF
ROUNDS TILL THE NO OF TRIALS PROVIDED AS PARAMETER
TO THE FUNCTION AND ALSO RETURNS THE NUMBER OF AVERAGE 
ROUNDS IT TAKES FOR THE TWO PIECES TO MEET UP
*/
double keep_simulating(int no_of_trials , int row , int col){

    int iter_var;
    int rounds_to_meet_up = 0;
    for (iter_var = 0; iter_var < no_of_trials ; iter_var++){

        if (no_of_trials <= 5){
            printf("Simulation %d\n", iter_var);
        }
        rounds_to_meet_up += one_trial_meet_up(row , col , no_of_trials); //NO OF ROUNDS IT TAKES TO MEET UP

    }

    return ((double) rounds_to_meet_up / (double) no_of_trials);
}


int main(){

    int row,col,seed,no_of_trials;
    double av_rounds_to_meet_up;

    seed = get_valid_seed();
    srand(seed);
    row = get_valid_row();
    col = get_valid_col();
    no_of_trials = get_valid_no_of_trials();

    av_rounds_to_meet_up = keep_simulating(no_of_trials , row , col);
    
    printf("On average it takes %.2lf rounds on a board %d X %d for the "
           "pieces to meet.", av_rounds_to_meet_up , row , col);

    return 0;
}