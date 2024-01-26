#include <stdio.h>

void edit(int *y);
int main(){
    int x;
    printf("Enter value of x: ");
    scanf("%d",&x);
    printf("Value of x before calling : %d\n",x);
    edit(&x); // the value of x incremented by 1 
    printf("Value of x after calling : %d\n",x);
    return 0;
}

void edit(int *y){ // call by refrence funtion
    *y+=1; // we can't use *y++ as it will increment the pointer to point for next item
          //instead we use *y+=1 
}