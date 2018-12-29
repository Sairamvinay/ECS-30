/* THIS PROGRAM CONVERTS TEMPERATURES
AND DISTANCES FROM ONE UNIT 
TO ANOTHER BY ASKING THE USER
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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


/* THIS FUNCTION CHECKS WHETHER THE GIVEN TEMPERATURE UNIT
IS EXISTANT OR NOT */
void check_correct_temp_suffix(char unit){

	//tolower is from ctype to ignore upper case.

	if (((tolower(unit)) != 'f') && ((tolower(unit)) != 'c') && ((tolower(unit)) !='k'))
	{
		printf("%c is not a valid temperature type. Ending program.",unit);
		exit(0);
	}

}


/* THIS FUNCTION CHECKS WHETHER THE GIVEN TEMPERATURE UNIT
IS EXISTANT OR NOT */
void check_correct_dist_suffix(char unit){

	if (((tolower(unit)) != 'i') && ((tolower(unit)) != 'y') && 
		((tolower(unit)) != 'f') && ((tolower(unit) != 'm'))){

			printf("%c is not a valid distance type. Ending program.",unit);
			exit(0);
		}
}


/*THIS FUNCTION CONVERTS FROM CELSIUS TO THAT TO_UNIT
PROVIDED AS PARAMETERS AND PRINTS THE CORRESPONDING RESULT
*/
void from_celsius(char to_unit,double from_value, double to_value){

	if ((tolower(to_unit)) == 'f'){
		to_value = (from_value * 9.0 / 5.0) + 32.0;
		printf("%.2lfC is %.2lfF",from_value,to_value);
	}

	else if ((tolower(to_unit)) == 'k'){
		to_value = from_value + 273.15;
		printf("%.2lfC is %.2lfK",from_value,to_value);
	}

	else{
		to_value=from_value;
		printf("%.2lfC is %.2lfC",from_value,to_value);
	}
}


/*THIS FUNCTION CONVERTS FROM FAHRENHEIT TO THAT TO_UNIT
PROVIDED IN THE FUNCTIONS AS PARAMETERS AND PRINTS THE CORRESPONDING 
RESULT
*/
void from_fahrenheit(char to_unit,double from_value,double to_value){

	if ((tolower(to_unit)) == 'c'){

		to_value = (from_value - 32.0) * 5.0 / 9.0;
		printf("%.2lfF is %.2lfC",from_value,to_value);
	}

	else if ((tolower(to_unit)) == 'k'){

		to_value = ((from_value - 32.0) * 5.0 / 9.0) + 273.15;	
		printf("%.2lfF is %.2lfK",from_value,to_value);
	}

	else{
		to_value = from_value;
		printf("%.2lfF is %.2lfF",from_value,to_value);	
	}
}


/*THIS FUNCTION CONVERTS FROM  KELVIN TO THAT TO_UNIT
PROVIDED IN THE FUNCTIONS AS PARAMETERS AND PRINTS THE CORRESPONDING 
RESULT
*/
void from_kelvin(char to_unit,double from_value, double to_value){

	if ((tolower(to_unit)) == 'c'){

		to_value = from_value - 273.15; 
		printf("%.2lfK is %.2lfC",from_value,to_value);
	}

	else if ((tolower(to_unit)) == 'f'){
		to_value = ((from_value - 273.15) * 9.0 / 5.0) + 32.0;
		printf("%.2lfK is %.2lfF",from_value,to_value);
	}

	else{
		to_value=from_value;
		printf("%.2lfK is %.2lfK",from_value,to_value);
	}
}


/* THIS FUNCTION CONVERTS FROM INCHES TO THAT TO_UNIT
PROVIDED IN THE FUNCTIONS AS PARAMETERS AND PRINTS THE CORRESPONDING 
RESULT
*/
void from_inch(char to_unit,double from_value, double to_value){

	if ((tolower(to_unit)) == 'f'){
		to_value = from_value / 12.0;
		printf("%.2lfI is %.2lfF",from_value,to_value);
	}

	else if ((tolower(to_unit)) == 'y'){
		to_value = from_value / 36.0;
		printf("%.2lfI is %.2lfY",from_value,to_value);
	}

	else if ((tolower(to_unit)) == 'm'){
		to_value = from_value / 63360.0;
		printf("%.2lfI is %.2lfM",from_value,to_value);
	}

	else{
		to_value = from_value;
		printf("%.2lfI is %.2lfI",from_value,to_value);
	}
}


/*THIS FUNCTION CONVERTS FROM FEET TO THAT TO_UNIT
PROVIDED IN THE FUNCTIONS AS PARAMETERS AND PRINTS THE CORRESPONDING 
RESULT
*/
void from_feet(char to_unit,double from_value,double to_value){
	if ((tolower(to_unit)) == 'i'){
		to_value = from_value * 12.0;
		printf("%.2lfF is %.2lfI",from_value,to_value);
	}

	else if ((tolower(to_unit)) == 'y'){
		to_value = from_value / 3.0;
		printf("%.2lfF is %.2lfY",from_value,to_value);
	}

	else if ((tolower(to_unit)) == 'm'){
		to_value = from_value / 5280.0;
		printf("%.2lfF is %.2lfM",from_value,to_value);
	}

	else{
		to_value = from_value;
		printf("%.2lfF is %.2lfF",from_value,to_value);
	}
}

/*THIS FUNCTION CONVERTS FROM YARDS TO THAT TO_UNIT
PROVIDED IN THE FUNCTIONS AS PARAMETERS AND PRINTS THE CORRESPONDING 
RESULT
*/
void from_yards(char to_unit,double from_value, double to_value){
	if ((tolower(to_unit)) == 'i'){
		to_value = from_value * 36.0;
		printf("%.2lfY is %.2lfI",from_value,to_value);
	}

	else if ((tolower(to_unit)) == 'f'){
		to_value = from_value * 3.0;
		printf("%.2lfY is %.2lfF",from_value,to_value);
	}

	else if ((tolower(to_unit)) == 'm'){
		to_value = from_value / 1760.0;
		printf("%.2lfY is %.2lfM",from_value,to_value);
	}

	else{
		to_value = from_value;
		printf("%.2lfY is %.2lfY",from_value,to_value);
	}
}



/*THIS FUNCTION CONVERTS FROM MILES TO THAT TO_UNIT
PROVIDED IN THE FUNCTIONS AS PARAMETERS AND PRINTS THE CORRESPONDING 
RESULT
*/
void from_miles(char to_unit,double from_value,double to_value){
	if ((tolower(to_unit)) == 'i'){
		to_value = from_value * 63360.0;
		printf("%.2lfM is %.2lfI",from_value,to_value);
	}

	else if ((tolower(to_unit)) == 'f'){
		to_value = from_value * 5280.0;
		printf("%.2lfM is %.2lfF",from_value,to_value);
	}

	else if ((tolower(to_unit)) == 'y'){
		to_value = from_value * 1760.0;
		printf("%.2lfM is %.2lfY",from_value,to_value);
	}

	else{
		to_value = from_value;
		printf("%.2lfM is %.2lfM",from_value,to_value);
	}
}



/*THIS FUNCTION CHECKS WHETHER THE USER 
HAS GIVEN THE CORRECT VALUE FOR CONVERTING
TEMPERATURE OR DISTANCE AND IF THEN IT INPUTS
THE VALUES TO CONVERT FROM USER THROUGH THE FUNCTION 
AND IF NOT IT GIVES A MESSAGE*/

void check_conversion_type(char choice,char from_unit,char to_unit,double from_value,double to_value){

	int num_args_read;
	if ((tolower(choice)) == 't'){
		
		printf("Enter the temperature followed by its suffix (F, C, or K): ");
		num_args_read = scanf(" %lf %c",&from_value,&from_unit);
		assert_formating(num_args_read,2);
		check_correct_temp_suffix(from_unit);
		
		printf("Enter the new unit type (F, C, or K): ");
		num_args_read = scanf(" %c",&to_unit);
		assert_formating(num_args_read,1);
		check_correct_temp_suffix(to_unit);

		if ((tolower(from_unit)) == 'c'){

			from_celsius(to_unit,from_value,to_value);
		}

		else if ((tolower(from_unit)) == 'f'){
			from_fahrenheit(to_unit,from_value,to_value);
		}

		else{
			from_kelvin(to_unit,from_value,to_value);
		}
	}

	
	else if ((tolower(choice)) == 'd'){
		printf("Enter the distance followed by its suffix (I,F,Y,M): ");
		num_args_read = scanf(" %lf %c",&from_value,&from_unit);
		assert_formating(num_args_read,2);
		check_correct_dist_suffix(from_unit);

		printf("Enter the new unit type (I,F,Y,M): ");
		num_args_read = scanf(" %c",&to_unit);
		assert_formating(num_args_read,1);
		check_correct_dist_suffix(to_unit);

		if ((tolower(from_unit)) == 'i'){
			from_inch(to_unit,from_value,to_value);
		}

		else if ((tolower(from_unit)) == 'f'){
			from_feet(to_unit,from_value,to_value);
		}

		else if ((tolower(from_unit)) == 'y'){
			from_yards(to_unit,from_value,to_value);
		}

		else {
			from_miles(to_unit,from_value,to_value);
		}
	}

	

	else{
		printf("Unknown conversion type %c chosen. Ending Program.",choice);
		exit(0);
	}	
}







int main(){

	double from_value=0.0,to_value=0.0; //FROM_VALUE BEFORE CONVERSION AND TO VALUE AFTER CONVERSION
	char from_unit=' ',to_unit=' ',choice;
	int num_args_read;
	printf("Pick the type of conversion that you would like to do.\n");
	printf("T or t for temperature\n");
	printf("D or d for distance\n");
	printf("Enter your choice: ");
	num_args_read = scanf(" %c",&choice);
	assert_formating(num_args_read,1);
	check_conversion_type(choice,from_unit,to_unit,from_value,to_value);
	return 0;
}
