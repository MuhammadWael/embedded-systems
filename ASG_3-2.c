#include <stdio.h>//for using printf and scanf 

int fibonacci(int limit);
int main(){
    int fib; // the varible refere to last number of fibbonaci's series
    printf("Enter number of terms: "); // user frindly interface
    scanf("%d",&fib);
    printf("Fibbonacci's Series : ");
    for (int i = 0; i < fib - 1; i++)
    {
        printf("%d ,",fibonacci(i)); //for loop for printing the values 
    }
    printf("%d",fibonacci(fib - 1)); // the last item printed with out the format of comma(,)
    
    return 0;
}
int fibonacci(int limit){
    if(limit == 0) // base cases of recursion (0,1,2)
        return 0;
    else if(limit == 1 || limit == 2) 
        return 1;
    else // the recusive call for function 
        return fibonacci(limit - 1) + fibonacci(limit - 2);   
}