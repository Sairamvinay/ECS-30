#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
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


/*
THIS FUNCTION KEEPS PROMPTING THE
USER FOR A VALID INTEGER INPUT
*/
int get_valid_int(char prompt[])
{
	int num_args_read;
	int integer_val;
	do{
		printf("%s",prompt);
		num_args_read = scanf("%d",&integer_val);
	
	} while ((!(is_valid_formatting(num_args_read,2))) && (integer_val <=0));

	return integer_val;
}



/*
THIS FUNCTION INPUTS THE MATRICES FROM THE USER
*/
void input_matrix(int matrix[][100],int rows,int cols,char prompt[]){

	int i,j;
	printf("%s\n",prompt);
	for (i=0;i<rows;i++){
		for (j=0;j<cols;j++){

			scanf("%d",&matrix[i][j]);
		}
	}
}


/*
THIS FUNCTION ADDS BOTH THE MATRICES AND STORES
THE SUM IN THE THIRD MATRIX.
DOES NOT RETURN ANYTHING NUT PRINTS THE ANSWER
*/
void sum_matrix(int matrix_A[][100],int matrix_B[][100],int rows,int cols){

	int i,j;
	int mat_sum[100][100];
	printf("A + B =\n");
	for (i=0;i<rows;i++){
		for (j=0;j<cols;j++){

			mat_sum[i][j] = matrix_A[i][j] + matrix_B[i][j];
		}
	}


	/*THESE LOOPS DISPLAY THE SUM MATRIX*/
	for (i=0;i<rows;i++){
		for (j=0;j<cols;j++){
			printf("%d ",mat_sum[i][j]);
		}
	printf("\n");
	}
}


int main(){

	int matrix_A[100][100],matrix_B[100][100];
	int rows,cols;
	rows = get_valid_int("Please enter the number of rows: ");
	cols = get_valid_int("Please enter the number of columns: ");

	input_matrix(matrix_A,rows,cols,"Enter Matrix A");
	input_matrix(matrix_B,rows,cols,"Enter Matrix B");

	sum_matrix(matrix_A,matrix_B,rows,cols);
	return 0;
}