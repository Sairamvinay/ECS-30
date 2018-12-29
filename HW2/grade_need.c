/* THIS PROGRAM CALCULATES THE MINIMUM PERCENT NEEDED
ON A FINAL TO GET A DESIRED GRADE IN THE CLASS
*/

#include <stdio.h>
#include <stdlib.h>


/* THIS FUNCTION CHECKS WHETHER THE INPUT 
IS FORMATTED PROPERLY IF WRONG THEN IT EXITS
*/
void assert_formating(int num_args_read,int num_args_reqd)
{

	char new_line='\n';
	if (num_args_read != num_args_reqd){
		printf("Invalid formatting. Ending program.\n");
		exit(0);
	}
	scanf("%c",&new_line);
	if (new_line != '\n'){
		printf("Invalid formatting. Ending program.\n");
		exit(0);
	}
}




/* THIS FUNCTION CHECKS WHETHER THE ENTERED GRADE
IS EXISTENT OR NOT.
ALSO IF EXISTENT THEN IT ASSIGNS THE VALUE
TO THE MINIMUM PERCENT NEEDED AS PER THE EXISTENT GRADE.
AND IF NOT IT ENDS THE PROGRAM
*/
double check_grade(char grade_needed,double min_percent_for_grade){

	switch(grade_needed){

		case 'a':                  //CHECKS WHETHER 'a' or 'A' IS ENTERED
		case 'A':{

			return min_percent_for_grade = 90.0;
			
		}

		
		case 'b':                  //CHECKS WHETHER 'b' or 'B' IS ENTERED
		case 'B':{

			return min_percent_for_grade = 80.0;
			
		}

		
		case 'c':                  //CHECKS WHETHER 'c' or 'C' IS ENTERED
		case 'C':{

			return min_percent_for_grade = 70.0;
			
		}

		
		case 'd':                  //CHECKS WHETHER 'd' or 'D' IS ENTERED
		case 'D':{

			return min_percent_for_grade = 60.0;

		}

		case 'f':
		case 'F':{

			return min_percent_for_grade = 0.0;
			
		}

		default:{

			//CHECKS WHETHER THE USER ENTERED A WRONG CHARACTER

			printf("Unknown Grade Received: %c. Ending program.",grade_needed);
            exit(0);   
		}                   
	}
}




/* THIS FUNCTION CHECKS WHETHER THE USER INPUT FOR ANY PERCENT VALUE 
	THAT IS WEIGHT OF FINAL OR CURRENT PERCENT IS RIGHT OR WRONG 
	IF WRONG INPUT THEN THE PROGRAM ENDS
*/
void check_percent(double user_inp_percent_val){
	
    
    if (user_inp_percent_val < 0){

    	printf("The number you last entered should have been positive. ");
    	printf("Ending program.");
    	exit(0);
    }
}   




/* THIS FUNCTION CALCULATES THE FINAL GRADE AND THEN CHECKS AND PRINTS
THE FINAL GRADE ACCORDINGLY AS IT CHECKS WHETHER THE GRADE IS ACHEIVABLE AS IN BETWEEN 
0 AND 100 OR ELSE PRINTS THE REQUIRES MESSAGE 
*/

void calc_check_and_print_final_grade(double min_percent_for_grade, double weight_of_final, double grade_in_final, double curr_percent, char grade_needed){

	// CALCULATION

	double weight_of_others = 100.0 - weight_of_final;    //STORES THE WEIGHT OF OTHER ASSIGNMENTS THAN FINAL

	/* THE FORMULA IS  : 
	FINAL PERCENTAGE (IN THIS CASE MIN_PERCENT_NEEDED) = (CURRENT PERCENT * WEIGHT OF OTHERS(%)) + (WEIGHT OF FINAL(%) * GRADE IN FINAL) 
	*/

	grade_in_final  =  (min_percent_for_grade - (weight_of_others * curr_percent / 100.0)) * 100.0 / (weight_of_final) ;  
	
    //CHECK AND PRINT THE FINAL GRADE 
    
    if (grade_in_final < 0.0){

    	printf("You cannot score low enough on the final to get a %c in the class.",grade_needed);

    }

    else if ((grade_in_final >= 0.0) && (grade_in_final <= 100.0)){

    	printf("You need a grade of at least %.2lf%% on the final ",grade_in_final);
        printf("to get a %c in the class.",grade_needed);
    }

    else{
    	
        printf("You cannot get a %c in the class because you would need to score ", grade_needed);
        printf("at least %.2lf%% on the final.",grade_in_final);}
}

int main()
{
	double min_percent_for_grade= 0.0 , weight_of_final;
	double grade_in_final = 0.0 , curr_percent ;                // JUST INITIALIZING THOSE VARIABLES THAT GET THEIR VALUES THROUGH FUNCTIONS 
	char grade_needed;
	int num_args_read;

	/* INPUTTING THE GRADE NEEDED AND THE CURRENT PERCENT 
 	   AND THE WEIGHT OF FINAL AND ALSO CHECKS THE PROPER FORMATTING
 	*/

	printf("Enter the grade you want in the class: ");
	num_args_read = scanf(" %c",&grade_needed);
	assert_formating(num_args_read,1);
	min_percent_for_grade = check_grade(grade_needed,min_percent_for_grade);


	printf("Enter your current percent in the class: ");
	num_args_read = scanf(" %lf",&curr_percent);
	assert_formating(num_args_read,1);
	check_percent(curr_percent);


	printf("Enter the weight of the final: ");
	num_args_read = scanf(" %lf",&weight_of_final);
	assert_formating(num_args_read,1);
	check_percent(weight_of_final);

    calc_check_and_print_final_grade(min_percent_for_grade,weight_of_final,grade_in_final,curr_percent,grade_needed);
    return 0;
}
