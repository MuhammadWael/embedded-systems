//Code for identifing odd or even without using modoulus operator (%) 
// declaring the needed library for scanf and printf
#include<stdio.h>

int main()
{
    //program intro for user to know the input
    printf("Enter the number");
    int number,even=0,odd=0;
    scanf("%d",&number);
    /*as the number is (int) so it trunckate the floating decimal point
    leading to a diffrence between the value of devision by 2and the actuall value in odd numbers 
    while being the same in even values ( as no fraction when dividing by 2 )*/ 
    if((number/2)*2 == number)
        even++; // incrementing the value of even to be shown as required 
    else
        odd++;
    printf("The number is odd  = %d\n",odd);
    printf("The number is even = %d\n",even);
    
    return 0;
}
