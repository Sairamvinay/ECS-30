#include <stdio.h>
#include <stdlib.h>
/*
THIS FUNCTION READS ONE LINE OF A FILE
*/
char *read_line(FILE *file){
   
   char letter='\0';
   char *line =NULL;
   int j=0;
   fscanf(file,"%c",&letter);
   while (!feof(file)){
          j++;
          line = (char *) realloc(line, j*sizeof(char));
          line[j-1] = letter;
          if (letter == '\n')
             break;
             
          fscanf(file,"%c",&letter);          
       }
          
   
   if (line != NULL){
      j++;
      line= (char *)realloc( line, (j+1)*sizeof(char));
      line[j-1]=letter;
      line[j] = '\0';
   }
   
   return line;
}
   
/*
THIS FUNCTION READS THE LINES OF A FILE
*/
void read_lines(FILE *fp, char ***lines, int *num_lines){
    
    int i;
    for (i=0;!feof(fp);i++){
       *lines = (char **) realloc(*lines, (i+1) * sizeof(char*));
       (*lines)[i] = read_line(fp);
    }
    
    if (ftell(fp)== 0){
       
       *lines = NULL;
       *num_lines = 0;
    }
    else{
       
       *num_lines = i-1;
    }    
}



/*
THIS FUNCTION READS THE LAST N LINES OF THE FILE PROVIDED AS COMMAND LINE ARGUMENTS
*/
void print_tail_lines(FILE *fp, char **lines, int num_lines_to_print,int num_lines){
     
     int i;
     if ((num_lines_to_print <= num_lines) && (num_lines_to_print >= 1)){
        for (i=num_lines-num_lines_to_print;i<num_lines;i++){
           printf("%s",lines[i]);
        }
     }
     
     else if (num_lines_to_print > num_lines){
        
        for (i=0;i<num_lines;i++){
           printf("%s",lines[i]);
        }
     }
}     




/*
THIS FUNCTION FREES THE CRETED MEMORY FOR THE LINES ARRAY
*/
void free_lines(char** lines, int num_lines){
	int i;
	
	for(i = 0 ; i < num_lines; ++i){
		free(lines[i]);
	}
	
	if(lines != NULL && num_lines > 0){
		free(lines);
	}

}


/*
THIS FUNCTION VALIDATES THE INPUT PROVIDED IN THE COMMAND LINE
*/
FILE* validate_input(FILE *fp,int argc, char* argv[]){

	if(argc < 3){
		printf("Not enough arguments entered.\nEnding program.\n");
		exit(0);
	}
	else if(argc > 3){
		printf("Too many arguments entered.\nEnding program.\n");
		exit(0);
	}
	

	if(fp == NULL){
		printf("Unable to open file: %s\nEnding program.\n", argv[1]);
		exit(0);
	} 
	
	return fp;
}



int main(int argc, char* argv[]){
	char** lines = NULL;
	int num_lines = 0;
	int num_lines_to_print = 0;
	sscanf(argv[2],"%d",&num_lines_to_print);
	FILE *fp = fopen(argv[1], "r");
	fp = validate_input(fp,argc, argv);
	read_lines(fp, &lines, &num_lines);
	print_tail_lines(fp,lines,num_lines_to_print,num_lines);
	free_lines(lines, num_lines);
	fclose(fp);

	return 0;
}
