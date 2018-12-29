#include <stdio.h>
#include <math.h>

int main(){

//THIS PROGRAM CALCULATES THE MONTHLY PAYMENT AND COST OF BORROWING A LOAN

double principal,interest_pa,interest_pm,monthly_payment,total_payment,cost_of_loan;
int no_of_payments;

//INPUTTING

printf("Please enter the amount of money you borrowed: $");
scanf("%lf",&principal);
printf("Please enter the annual interest rate: ");
scanf("%lf",&interest_pa);
printf("Please enter the number of payments to be made: ");
scanf("%d",&no_of_payments);

//CALCULATION

interest_pm = interest_pa / 12.0 ;
monthly_payment = (interest_pm * principal) / (1.0 - pow(1.0 + interest_pm,-no_of_payments));
total_payment = monthly_payment * no_of_payments;
cost_of_loan = total_payment - principal;

//PRINTING THE RESULT

printf("A loan of $%.2lf with an annual interest of %.2lf payed off over %d months will have monthly payments of $%.2lf.\n",principal,interest_pa,no_of_payments,monthly_payment);

printf("In total you will pay $%.2lf, making the cost of your loan $%.2lf.",total_payment,cost_of_loan);
return 0;
}
