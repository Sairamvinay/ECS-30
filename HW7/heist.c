#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/*
THIS STRUCTURE IS USED TO STORE ITEM AS STRUCTURE WITH
ATTRIBUTES VALUE AND WEIGHT
*/
typedef struct item_struct{
   
   int value;
   int weight;

}ITEM;





//FUNCTION TO CHECK THE VALID FORMATTING OF THE INPUT
bool is_valid_formatting(int num_args_read, int num_args_reqd){
   
   bool is_valid = true;
   if (num_args_read != num_args_reqd)
      is_valid = false;
   
   char newline = '\n';
   do{
     
     scanf("%c",&newline);
     if (!isspace(newline)){
        is_valid = false;
     }
   } while (newline != '\n');
   
   return is_valid;
}



//FUNCTION TO GET VALID SINGLE INTEGER INPUT
int get_valid_int(char prompt[]){
   
   int integer,num_args_read;
   do{
     
     printf("%s",prompt);
     num_args_read = scanf("%d",&integer);
   
   }while((!is_valid_formatting(num_args_read,1)) || (integer <= 0));
   
   return integer;
}





//THIS FUNCTION IS USED TO GET THE VALID VALUE FOR ITEM ARRAY  
ITEM* get_valid_item(int num_items){

   int i;
   ITEM *items = (ITEM *)malloc(num_items * sizeof(ITEM));
   printf("Enter your items, one per line (value weight):\n");
   for (i=0;i<num_items;i++){ 
    
      scanf("%d %d",&items[i].value,&items[i].weight);
   }
   
   return items;
}



//THIS FUNCTION CALCULATES THE SUM OF THE WEIGHT AND THE VALUES OF EACH COMBINATION
int sum_weight_value(ITEM *list, int max_combs,int *value){
   
   int i,sum=0;
   *value =0;
   for (i=0;i<max_combs;i++){
     
     sum+=list[i].weight;
     (*value)+=list[i].value;
     
   }
   return sum;
}
      


//THIS FUNCTION CREATES THE COMBINATIONS AND FINDS THE LARGEST OF THE VALUES WITHIN THE WEIGHT OF THE BAG
void _combs(ITEM* list, int len, int combs, ITEM* cur_comb, int max_combs,int max_wt_bag,int *largest){
  
  int i;
  if(combs == 0){ //if k is 0 we have completed a combination
     
     
     int value =0;
     int sum_weight = sum_weight_value(cur_comb,max_combs,&value);
     if (sum_weight < max_wt_bag){
        
        if ((*largest) < value)
           (*largest) = value;
        
     }
  }   
     
  
  else if(combs > len){ //not enough elements to complete the combination
    return ;
  }
  
  else{
    for(i = 0; i < len; i++){ //for each element in the list
      cur_comb[max_combs - combs] = list[i];//add it to our current combination
      _combs(list + i + 1, len - i - 1,  combs - 1, cur_comb, max_combs,max_wt_bag,largest); //create a combination of the rest
    }
  }
}


// THIS FUNCTION KEEPS CALLING _COMBS FOR GENERTAING DIFFERENT COMBINATIONS OF THE ITEMS
void combs(ITEM* list, int len, int combs,int max_wt_bag){
  
  ITEM* cur_comb;
  if(combs > len){
    printf("Empty List\n");
  } 
  
  else{
    
    int j;
    int largest = 0;
    for (j=1;j<=len;j++){
       
       cur_comb = (ITEM*) malloc(j * sizeof(ITEM)); //make space for a combination
       _combs(list, len, j, cur_comb, j,max_wt_bag,&largest); //create the combinations
       free(cur_comb);//free up the space malloced
    }
    printf("They most profitable heist will net you $%d in total.\n",largest);
  }
}






int main(){
   
   int max_wt_bag = get_valid_int("Enter the maximum amount of weight that your bag can hold: ");
   int num_items = get_valid_int("Enter the number of items that are in the jewelry store: ");
   ITEM* items = get_valid_item(num_items);
   combs(items,num_items,num_items,max_wt_bag);
   free(items);
   return 0;
   
}
