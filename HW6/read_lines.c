#include "read_lines.h"
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

