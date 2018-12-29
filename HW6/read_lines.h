#ifndef READ_LINES_H
   #define READ_LINES_H
   #include <stdio.h>
   #include <stdlib.h>
   char *read_line(FILE *file);
   void read_lines(FILE *fp, char ***lines, int *num_lines); 
#endif
