#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

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
THIS FUNCTION AKS THE USER TO
ENTER AN INTEGER WHICH MUST BE
GREATER THAN 0 AND LESS THAN 29
*/

int get_valid_level(){

	int level,num_args_read;
	do{
		printf("Please enter how many levels of Pascal's Triangle you would like to see:");
		num_args_read = scanf("%d",&level);
	
	}while ((!is_valid_formatting(num_args_read,1)) || (level <0) || (level >=29));

	return level;

}

/*
THIS FUNCTION PRINTS OUT ALL THE 
VALUES FILLED IN THE PASCAL_VAL FUNCTION
PASSED AS AN ARGUMENT IN THE FUNCTION
*/
void print_pascal(int pascal_val[][28],int level)
{

	int a,b;
	for (a = 0; a<level;a++){
		for (b= 0; b <=a  ; b++)
		{
			printf(" %d ",pascal_val[a][b]);
		}

		printf("\n");
	}
}


/* 
THIS FUNCTION FILLS THE 2D ARRAY
PASCAL_VAL WITH ALL THE VALUES IN 
THE TRIANGLE UPTILL THAT LEVEL
*/

void fill_pascal(int level){

	int i=0,j;
	int pascal_val[28][28];

	for (i=0;i<level;i++){
		for (j=0;j<=i;j++){

			if ((i==j) || (j==0))
				pascal_val[i][j] = 1;

			else{

			    pascal_val[i][j] = pascal_val[i-1][j-1] + pascal_val[i-1][j];
			}
		}
	}
	print_pascal(pascal_val,level);
}



int main(){

	int level;
	level = get_valid_level();
	fill_pascal(level);
	return 0;
}
