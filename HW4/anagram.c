#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
THIS FUNCTION CONVERTS THE 
WHOLE GIVEN STRING INTO LOWER CASE
*/
void conv_to_lower_str(char str[])
{

	int len_str = strlen(str);
	int i;
	for (i=0 ; i<len_str ; i++)
	{
		str[i] = tolower(str[i]);
	}
}


/*THIS FUNCTION SORTS THE GIVEN STRING*/
void sort_string(char str[]){

	int len_str = strlen(str);
	int i,j;
	for (i=0;i<len_str;i++){

		int small_char_index = i;
		char small_char = str[i];
		for (j=i+1;j<len_str;j++)
		{

			if (str[j] < small_char){
				small_char = str[j];
				small_char_index = j;
			}
		}
	
	char temp = str[i];
	str[i] = small_char;
	str[small_char_index] = temp;
	}

	str[len_str]='\0';
}

/*
THIS FUNCTION CHECKS THE STRINGS ARE ANAGRAMS 
OR NOT BY COMPARING THEIR SORTED STRINGS
*/

void check_anagram(char str1[], char str2[])
{	
	char first_str[20];
	char second_str[20];
	strcpy(first_str , str1);
	strcpy(second_str , str2);
	//FOR PRINTING THE STRINGS IN THE FINAL OUTPUT
	if (strlen(str1) != strlen(str2))
	{
		printf("%s is NOT an anagram of %s",str1,str2);
	}

	else{

		conv_to_lower_str(str1);
	    conv_to_lower_str(str2);
        sort_string(str1);
        sort_string(str2); 

		if (strcmp(str1,str2) == 0){
			   
	    //CLEARLY ANAGRAM STRINGS HAVE THE SAME STRINGS AFTER GETTING SORTED
		    printf("%s is an anagram of %s",first_str,second_str);
		}

		else{

			printf("%s is NOT an anagram of %s",first_str,second_str);
		}
	}
}




int main(){
	char str1[20] = "";
	char str2[20] = "";
	printf("Please enter the first word: ");
	fgets(str1,20,stdin);
	printf("Please enter the second word: ");
	fgets(str2,20,stdin);
	str1[strlen(str1) - 1] = '\0';
	str2[strlen(str2) - 1] = '\0';
	check_anagram(str1,str2);
	return 0;
}

