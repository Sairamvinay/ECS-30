#include <stdio.h>

int main(){

/* THIS PROGRAM IS USED TO FIND THE GRADE IN THE FINAL TO ACHIEVE THE REQUIRED GRADE IN CLASS GIVEN YOUR CURRENT PERCENT AND THE PERCENT REQUIRED TO GET THAT GRADE (ALSO GIVEN) */


double curr_perc,weight_of_final,want_perc,final_mark;
char want_grade;

//INPUTTING THE REQUIRED DETAILS

printf("Enter the grade you want in the class: ");
scanf("%c",&want_grade);

printf("Enter the percent in the class you need in the class to get that grade: ");
scanf("%lf",&want_perc);

printf("Enter your current percent in the class: ");
scanf("%lf",&curr_perc);

printf("Enter the weight of the final: ");
scanf("%lf",&weight_of_final);

//CALCULATION

double rest_marks = (100.0 - weight_of_final) * curr_perc / 100.0;
final_mark = (want_perc - rest_marks) * 100.0 / weight_of_final; 

/*the wanted percentage is given by:

 wanted percent = (weight of final * final mark / 100) + ((100-weight of final) * current percentage /100)

*/

 
//PRINTING THE RESULT

printf("You need to get at least %.2lf%% on the final to get a %c in the class.",final_mark,want_grade);
return 0;
}
