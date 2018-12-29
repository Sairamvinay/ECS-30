#include <stdio.h>
#include <stdlib.h>

/*
THIS FUNCTION CALCULATES THE VALUE OF FOO RECURSIVELY
*/
long foo(int number,int foo_0,int foo_1,int foo_2){
  
   if (number == 0)
      return foo_0;
   
   else if (number == 1)
      return foo_1;
   
   else if (number == 2)
      return foo_2;
   
   else{
      return foo(number-1, foo_1 , foo_2 , foo_0 + foo_1 + foo_2);
  }
}


/*
THIS FUNCTION CALLS FOO WITH 
  FOO(0) = 2
  FOO(1) = 3
  FOO(2) = 5
*/
long call_foo(int number){
    
    return foo(number,2,3,5);
}


/*
THIS FUNCTION CHECKS THE VALIDITY OF THE INPUT
*/
void check_validity(int argc,char **argv){
   
   if (argc > 2){
      printf("Too many arguments provided\n");
      exit(0);
   }
   
   else if (argc < 2){
      printf("Not many arguments provided\n");
      exit(0);
   }
}



int main(int argc, char **argv){
    
    
    check_validity(argc,argv);
    int number = atoi(argv[1]);
    long answer = call_foo(number);
    printf("foo(%d) = %ld",number,answer);
    return 0;
}

