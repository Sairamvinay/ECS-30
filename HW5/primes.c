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

int get_valid_int(char prompt[]){

	int integer_val,num_args_read;
	do{
		printf("%s:",prompt);
		num_args_read = scanf("%d",&integer_val);
	
	}while (!(is_valid_formatting(num_args_read,1)) || integer_val<=1);

	return integer_val;
}




/*
THIS FUNCTION STORES THE NUMBER OF PRIMES
BETWEEN 2 AND THE LIMIT PROVIDED IN AN ARRAY
BY DYNAMICALLY REALLOCATING IT USING REALLOC()
FUNCTION AND IT TAKES A DOUBLE POINTER AS INPUT
*/
int *check_and_return_prime(int limit,int *num_of_primes){

	int *prime_array= NULL;
	int i,j;
	int flag = 0;
	for (i=2;i<=limit;i++){
		for (j=2;j<i;j++){
			if (i%j == 0){
				flag = 1;
				break;
			}	

			else{

				flag=0;
			}
		}

		if (flag == 0){
			(*num_of_primes)++;
			prime_array =(int *) realloc(prime_array, (*num_of_primes) * sizeof(int));
			prime_array[(*num_of_primes)-1]=i;
		}
	}

	return prime_array;
}



/*
THIS FUNCTION PRINTS THE PRIMES STORED IN THE ARRAY
PRIME_ARRAY PASSED AS PARAMETER
*/
void print_primes(int *prime_array, int num_of_primes){

	int i;
	for (i=0;i<num_of_primes;i++){

		printf("%d\n",prime_array[i]);
	}
}


/*
THIS FUNCTION DELETES THE ALLOCATED MEMORY
FOR PRIME_ARRAY
*/
void del_array(int *prime_array){

	free(prime_array);
}


int main(){

	int limit;
	int *prime_array;
	int size_of_prime=0;
	limit = get_valid_int(" Enter a number greater than 1");
	prime_array = check_and_return_prime(limit,&size_of_prime);
	printf(" The primes between 2 and %d are:\n",limit);
	print_primes(prime_array,size_of_prime);
	del_array(prime_array);
	return 0;
}