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

/*
THIS FUNCTION KEEPS PROMPTING FOR THE 
CORRECT VALUE FOR THE DEPOSIT MONEY
UNLESS A VALID INPUT IS GIVEN
*/
double get_valid_deposit_money(){

    double deposit_money;
    int num_args_read;
    do{
        printf("Enter how much money you will be putting towards loans/retirement each month: ");
        num_args_read = scanf("%lf",&deposit_money);
    
    }while ((!is_valid_formatting(num_args_read,1)) || (deposit_money<=0));

    return deposit_money;
}


/*
THIS FUNCTION KEEPS PROMPTING FOR THE 
CORRECT VALUE FOR THE TOTAL LOAN
MONEY UNLESS A VALID INPUT IS GIVEN
*/
double get_valid_owe_loans(){

    double tot_loan_amt;
    int num_args_read;
    do{
        printf("Enter how much you owe in loans: ");
        num_args_read = scanf("%lf",&tot_loan_amt);
    
    }while ((!is_valid_formatting(num_args_read,1)) || (tot_loan_amt<=0));

    return tot_loan_amt;
}


/*
THIS FUNCTION KEEPS PROMPTING FOR THE 
CORRECT VALUE FOR THE ANNUAL INTEREST RATE
UNLESS A VALID INPUT IS GIVEN
RETURNS MONTHLY RETURN INTEREST RATE
*/
double get_valid_ann_int_rate(){
    
    double ann_int_rate;
    int num_args_read;
    do{
        printf("Enter the annual interest rate of the loans: ");
        num_args_read = scanf("%lf",&ann_int_rate);
    
    } while ((!is_valid_formatting(num_args_read,1)) || (ann_int_rate <=0));

    return ann_int_rate / 12.0;
}


/*
THIS FUNCTION KEEPS PROMPTING FOR THE 
CORRECT VALUE FOR THE MINIMUM MONTHLY LOAN 
PAYMENT UNLESS A VALID INPUT IS GIVEN
*/
double get_valid_min_monthly_loan(){

    double min_monthly_loan;
    int num_args_read;
    do{
        printf("Enter your minimum monthly loan payment: ");
        num_args_read = scanf("%lf",&min_monthly_loan);
    
    } while ((!is_valid_formatting(num_args_read,1)) || (min_monthly_loan<=0));

    return min_monthly_loan;
}


/*
THIS FUNCTION KEEPS PROMPTING FOR THE 
CORRECT VALUE FOR THE RETURN INTEREST RATE 
PAYMENT UNLESS A VALID INPUT IS GIVEN
RETURNS THE MONTHLY RATE
*/
double get_valid_return_int_rate(){

    double return_int_rate;
    int num_args_read;
    do{
        printf("Enter the annual rate of return you predict for your investments: ");
        num_args_read = scanf("%lf",&return_int_rate);
    
    } while ((!is_valid_formatting(num_args_read,1)) || (return_int_rate <=0));

    return return_int_rate / 12.0;
}



/*
THIS FUNCTION KEEPS PROMPTING FOR THE 
CORRECT VALUE FOR THE CURRENT AGE IN YEARS
UNLESS A VALID INPUT IS GIVEN
*/
int get_valid_curr_age(){

    int curr_age , num_args_read;
    do{
        printf("Enter your current age: ");
        num_args_read = scanf("%d",&curr_age);
    
    }while((!is_valid_formatting(num_args_read,1)) || (curr_age<=0));

    return curr_age;
}


/*
THIS FUNCTION KEEPS PROMPTING FOR THE 
CORRECT VALUE FOR THE RETIRE AGE IN YEARS
UNLESS A VALID INPUT IS GIVEN
*/
int get_valid_ret_age(int curr_age){
    int ret_age , num_args_read;
    do{
        printf("Enter the age you plan to retire at: ");
        num_args_read = scanf("%d",&ret_age);
    
    }while((!is_valid_formatting(num_args_read,1)) || (ret_age < curr_age));

    return ret_age ;


}

    
/*
THIS FUNCTION CHECKS WHTHERTHE MONEY SET FOR LOANS IS SUFFICIENT
OR NOT THROUGH CHECKING THE DIFFERENCE DEPOSIT AND LOAN VALUE
*/
void check_loan_money(double deposit_money , double min_monthly_loan){

    if ((deposit_money - min_monthly_loan) < 0){

        printf("You didn't set aside enough money to pay off our loans. Ending program.");
        exit(0);
    }
}



/*
THIS FUNCTION CALCULATES AND RETURNS THE TOTAL SAVINGS
MONEY IF ALL THE INVESTMENTS ARE MADE ON THE LOANS
*/
double thru_all_loan_pay(double deposit_money, double tot_loan_amt, double month_int_rate, 
double return_int_rate, int curr_age, int ret_age)

{ 
    int a;
    int time_period = (ret_age - curr_age) * 12;    //NO OF MONTHS OF WORK AND INVESTMENT
    double savings=0.0;
    double investment=0.0;
    for (a=0 ; a<time_period ; a++){


       tot_loan_amt = tot_loan_amt * (1.0 + month_int_rate) ;
       
       //IF ELSE FOR CHECKING WHETHER THE LOAN IS PAID OR NOT

       if ((tot_loan_amt -  deposit_money) >= 0)    
       {
        /*
        IF DIFFERENCE BETWEEN LOAN AMOUNT AND THE DEPOSIT MONEY
        IS STILL NON NEGATIVE (OR GREATER THAN OR EQUAL TO DEPOSIT MONEY) 
        */
        
        tot_loan_amt -= deposit_money;         // NO SAVINGS TILL LOAN IS PAID
       }

       else{
        
        savings = savings * (1.0 + return_int_rate);  //FIRST COMPOUND THE SAVINGS AND THEN KEEP ON ADDING THE SAVINGS = DEPOSIT CASH AFTER THE LOAN IS PAID
        investment = deposit_money - tot_loan_amt;
        savings += investment;
        tot_loan_amt =0.0  ;                           // LOAN IS FINISHED AND HENCE IT IS MADE 0
        

        //BECAUSE THE LOAN IS PAID AND NOW NEED TO INVEST ALL MY DEPOSIT MONEY INTO SAVINGS
       
       }
    }


    if (tot_loan_amt != 0){

        printf("Warning! After you retire you will still have %.2lf in loans left.\n",tot_loan_amt);
    }

    return savings;
}


/*
THIS FUNCTION CALCULATES AND RETURNS THE TOTAL SAVINGS
MONEY IF ONLY THE MINIMUM MONTHLY LOANS ARE PAID
*/
double thru_monthly_loan_pay(double deposit_money, double tot_loan_amt, double 
min_monthly_loan , double month_int_rate, double return_int_rate, int curr_age, int ret_age)
{

    int j;
    int time_period = (ret_age - curr_age) * 12;    //NO OF MONTHS OF WORK AND INVESTMENT
    double savings = 0.0;
    double investment = deposit_money - min_monthly_loan;


    

    for (j=0; j<time_period ; j++){

        tot_loan_amt = tot_loan_amt * (1.0 + month_int_rate); 

        //IF ELSE FOR CHECKING WHETHER THE LOAN IS PAID OR NOT
        if ((tot_loan_amt - min_monthly_loan) >= 0){

            tot_loan_amt -= min_monthly_loan;
            savings = savings * (1.0 + return_int_rate);
            savings += investment;                   // TILL LOAN IS PAID THE INVESTMENT MONEY IS THE DIFFERENCE IN THE DEPOSIT AND THE MINIMUM LOAN PAYMENT
        }

        else{

            savings = savings * (1.0 + return_int_rate);
            investment = deposit_money - tot_loan_amt;    //AFTER LOAN IS PAID THE INVESTMENT MONTHLY IS DEPOSIT MONEY
            savings += investment;
            tot_loan_amt = 0.0    ;                        // LOAN IS FINISHED AND HENCE IT IS MADE 0

        }
    }

    if (tot_loan_amt != 0){

        printf("Warning! After you retire you will still have $%.2lf in loans left.\n",tot_loan_amt);

    }


    return savings;
}




/*
THIS FUNCTION COMPARES WHETHER THE SAVINGS FROM PAYING OFF
ALL THE LOANS BEFORE INVESTING OR FROM PAYING THROUGH THE MINIMUM
MONTHLY LOAN PAYMENT IS HIGHER THAN THE OTHER.
*/
void check_savings(double savings_thru_min_loan_pay,double savings_thru_all_pay
,double deposit_money)
{
  if (savings_thru_min_loan_pay > savings_thru_all_pay)
  {

    printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
    
    printf("If you do you will have $%.2lf when you retire as opposed"
    " to $%.2lf if you payed off your loan before investing.",savings_thru_min_loan_pay,savings_thru_all_pay);
  }
  

  else 
  {

    printf("You should apply all $%.2lf towards your loan before making "
    "any investments.\n",deposit_money);
    
    printf("If you do you will have $%.2lf when you retire as opposed"
    " to $%.2lf if you only made minimum payments.",savings_thru_all_pay,savings_thru_min_loan_pay);
  }
  
}


int main()
{

    double deposit_money,min_monthly_loan,month_int_rate,return_int_rate;
    double tot_loan_amt, savings_thru_all_pay,savings_thru_min_loan_pay;
    int ret_age,curr_age;

    deposit_money = get_valid_deposit_money();
    tot_loan_amt = get_valid_owe_loans();
    month_int_rate = get_valid_ann_int_rate();
    min_monthly_loan = get_valid_min_monthly_loan();
    check_loan_money(deposit_money,min_monthly_loan);
    curr_age = get_valid_curr_age();
    ret_age = get_valid_ret_age(curr_age);
    return_int_rate = get_valid_return_int_rate();
    savings_thru_all_pay =thru_all_loan_pay(deposit_money,tot_loan_amt,month_int_rate,return_int_rate,curr_age,ret_age);
    savings_thru_min_loan_pay = thru_monthly_loan_pay(deposit_money, tot_loan_amt, min_monthly_loan, month_int_rate, return_int_rate, curr_age, ret_age);
    check_savings (savings_thru_min_loan_pay, savings_thru_all_pay,deposit_money);
    return 0;
}


