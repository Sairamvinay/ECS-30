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



/*
 THIS FUNCTION KEEPS PROMPTING USER FOR THE 
 NUMBER OF ITERATIONS TILL THE USERS ENTERS A 
 VALID INPUT CALLS IS_VALID_FORMATTING FOR 
 CHECKING THE VALIDATION OF THE INPUT
*/
int get_valid_iter_num(){

	int iter_num = 0;
	int num_args_read;
	do{
		printf("Enter the number of iterations to run: ");
		num_args_read = scanf("%d",&iter_num);
		
	
	}while ((!is_valid_formatting(num_args_read,1)) || (iter_num<=0));
	

	return iter_num;
}


/*
THIS FUNCTION GENERATES A RANDOM 
DOUBLE NUMBER BETWEEN THE ARGUMENTS 
LOW AND HIGH
*/
double rand_double(double low , double high){

	return low +  ( (double) rand()) /
					( ((double)RAND_MAX)/(high-low));
}


/*
THIS FUNCTION KEEPS GENERATING RANDOM POINTS (DOUBLE
VALUES FOR X AND Y COORDINATES) AND HENCE CHECKS WHETHER
THE GIVEN POINT IS INSIDE OR ON THE CIRCLE AND COUNTS THAT MANY POINTS
AND THEN RETURNS THE PROBABILITY BY DIVIDING THE NO OF SUCH POINTS BY THE
TOTAL NUMBER OF POINTS( NUMBER OF ITERATIONS ) AND THEN RETURN THE VALUE
OF PI BY MULTIPLYING THE PROBABILITY BY 4
*/
double calc_pi(int iter_num){
   
   int run_var;    //ITERATING VARIABLE
   
   int points_in_on_circle =0 ,total_points=0; 
   double x_coord , y_coord;
   
   for (run_var=0;run_var < iter_num; ++run_var){
   	 
   	 total_points++;
   	 x_coord = rand_double(-1.0,1.0);
   	 y_coord = rand_double(-1.0,1.0);

   	 if ((x_coord * x_coord) + (y_coord * y_coord) <= 1.0){

   	 	points_in_on_circle++;
   	 }
   	}

    double pi = 4.0 * ((double) points_in_on_circle / (double) total_points); //2ND TERM IS PROBABILITY
    return pi;   
}


int main()
{
	int iter_num,seed;
	double pi;
	seed = get_valid_seed();
	srand(seed);
	iter_num = get_valid_iter_num();
	pi = calc_pi(iter_num);
	printf("The value of pi is %.5lf.",pi);
	return 0;
}

