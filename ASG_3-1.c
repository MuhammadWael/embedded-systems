#include <stdio.h> //for using scanf and printf
//function prototype
void swap(int *x,int *y);
int main(){
    int first_number,second_number; //initialziation of variables
    //user friendly interface
    printf("Enter first number\n");
    scanf("%d",&first_number);
    printf("Enter second number\n");
    scanf("%d",&second_number);
    printf("before swaping\nx = %d\ty = %d\n",first_number,second_number);
    swap(&first_number,&second_number); //call by refrence function of swaping
    printf("after swaping\nx = %d\ty = %d\n",first_number,second_number);
    return 0;
}
void swap(int *x,int *y){ //swaping without using extra temprary varable
    *x = *x + *y; 
    *y = *x - *y;
    *x = *x - *y;
}