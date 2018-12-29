#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double calc_dist(int point1_x, int point1_y,int point2_x,int point2_y){
   
   return (double)sqrt((pow(point2_x-point1_x,2)) + (pow(point2_y-point1_y,2)));
}

//THIS FUNCTIONS CALCULATES THE PERIMETER OF THE FILE
double calculate_perimeter(FILE *file){
   
   int first_pt[2]; //ARRAY TO STORE FIRST POINT 
   int num_sides;
   int curr_x,curr_y;
   double perimeter = 0;
   fread(&num_sides,sizeof(int),1,file); //IT SHOULD READ THE NUMBER OF SIDES
   fread(first_pt,sizeof(int),2,file);// READS THE FIRST POINT INTO AN ARRAY;
   while (!feof(file)){
     
      fread(&curr_x,sizeof(int),1,file);
      fread(&curr_y,sizeof(int),1,file);
      perimeter += calc_dist(first_pt[0],first_pt[1],curr_x,curr_y);
      
      first_pt[0] = curr_x;
      first_pt[1] = curr_y;
   }
   
   rewind(file);   //THE FILE MUST GO BACK TO THE FIRST POINT SO I AM GOING TO THE START OF FILE AGAIN
   fread(&num_sides,sizeof(int),1,file);
   fread(&curr_x,sizeof(int),1,file);// FIRST POINT OF THE FILE IN CURR_X AND CURR_Y
   fread(&curr_y,sizeof(int),1,file);
   perimeter += calc_dist(first_pt[0],first_pt[1],curr_x,curr_y);
   
   return perimeter;
}
      
   
   



//THIS FUNCTIONS CHECKS WHETHER THE FILE IS EXISTANT OR NOT
void check_file(FILE *file){
   
   if (file==NULL)
      exit(0);
   
}


int main(int argc, char *argv[]){
   
   FILE *file = fopen(argv[1],"rb");
   double perimeter;
   
   perimeter = calculate_perimeter(file);
   printf("The perimeter is %.2lf",perimeter);
   fclose(file);
   return 0;

}
