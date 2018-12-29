#include <stdio.h>
int main(){

// THIS PROGRAM IS USED TO COMPUTE THE PRODUCT OF 2 COMPLEX NUMBERS

int real_comp1,real_comp2,imag_comp1,imag_comp2,real_prodcomp,imag_prodcomp;

//INPUTTING THE FIRST COMPLEX NUMBER

printf("Enter the first complex number in the form ai + b: ");
scanf("%d i + %d",&imag_comp1,&real_comp1);   //takes in the input in the form ai+b independent of the spaces between them

//INPUTTING THE SECOND COMPLEX NUMBER

printf("Enter the second complex number in the form ai + b: ");
scanf("%d i + %d",&imag_comp2,&real_comp2);

//CALCULATION

real_prodcomp = (real_comp1 * real_comp2) - (imag_comp1 * imag_comp2);  //computing the real part of the product complex number
imag_prodcomp = (real_comp1 * imag_comp2) + (real_comp2 * imag_comp1);  //computing the imaginary part of the product complex number

//PRINTING THE OUTPUT

printf("(%di + %d) * (%di + %d) = %di + %d",imag_comp1,real_comp1,imag_comp2,real_comp2,imag_prodcomp,real_prodcomp);
return 0;
}
