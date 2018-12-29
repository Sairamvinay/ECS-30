/*
THIS PROGRAM SOLVES A GIVEN QUADRATIC EQUATION 
TO FIND AND REPORT ITS POSSIBLE ROOTS BY
INPUTTING THE COEFFICIENTS 
*/ 

#include <stdio.h>
#include <math.h>

void check_and_print_soln(double coeffA, double coeffB, double coeffC){
    /* THIS FUNCTION CALCULATES THE DISCRIMINANT = (b*b) - (4*a*c)
       AND THEN USES ITS VALUE TO 
	   CHECK NUMBER OF REAL ROOTS AND OUTPUTS THEM
	*/

	//ROOT IS x= (-b (+/-) sqrt(DISCRIMINANT)/ (2.0 *a)  

	double discriminant,real_soln1,real_soln2;

	discriminant = pow(coeffB,2) - (4 * coeffA * coeffC);

	if (discriminant > 0)    // IN CASE OF 2 REAL ROOTS 
	{
		printf("There are 2 real solutions\n");
		
		real_soln1 = (-coeffB + sqrt(discriminant)) / (2.0 * coeffA); 
		real_soln2 = (-coeffB - sqrt(discriminant)) / (2.0 * coeffA);
		
		printf("Solution 1: %.2lf\n",real_soln1);
		printf("Solution 2: %.2lf",real_soln2);
	
	}

	else if (discriminant == 0)  //IN CASE OF 1 REAL ROOT
	{

		real_soln2 = real_soln1 = (-coeffB /(2.0 * coeffA));
		printf("There is one real solution: %.2lf",real_soln1);

	}

	else     //IN CASE OF NO REAL ROOTS
	{
		printf("There are no real solutions");
	} 
}
int main()
{
	

	double a_value,b_value,c_value;

	// INPUTTING OF THE COEFFICIENTS 
	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	
	printf("Please enter a: ");
	scanf(" %lf",&a_value);
	
	printf("Please enter b: ");
	scanf(" %lf",&b_value);
	
	printf("Please enter c: ");
	scanf(" %lf",&c_value);

    check_and_print_soln(a_value,b_value,c_value);        // CALLS THE FUNCTION TO CALCULATE THE REAL ROOTS (IF EXISTANT)

    return 0;
}
