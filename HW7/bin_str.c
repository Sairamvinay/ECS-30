#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* THIS FUNCTION CHECKS FOR A CHARACTER AND RETURNS POINTER TO FIRST OCCURENCE 
   IF NOT THEN RETURN NULL
*/
char *find_letter(char *str, char letter){

	int i=0;
	for (i=0;str[i]!='\0';i++){
		if (str[i] == letter)
			return str + i;
	}

	return NULL;
}



/*
RECURSIVE FUNCTION TO PRINT THE X
*/
void binary_string(char *str){

	char *x_char = find_letter(str,'x');
	if (x_char == NULL){
		printf("%s\n",str);
		return;
	}
	
	*x_char = '0';
	binary_string(str);
	*x_char = '1';
	binary_string(str);
	*x_char = 'x';
}



//THIS FUNCTION CHECKS THE VALIDITY OF THE INPUT PROVIDED
void check_validity(int argc){

	if (argc < 2){
		printf("Too few arguments provided\n");
		exit(0);
	}

	else if (argc > 2){
		printf("Too many arguments provided\n");
		exit(0);
	}
}

int main(int argc,char **argv){

	check_validity(argc);
	char *string = (char *)malloc((strlen(argv[1])) * sizeof(char));
	strcpy(string,argv[1]);
	binary_string(string);
	free(string);
	return 0;
}