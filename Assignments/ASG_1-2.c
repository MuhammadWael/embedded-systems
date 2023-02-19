
// declaring the needed library for scanf and printf
#include<stdio.h>
#define True 1
#define MAX_NUMBER_OF_BITS 31
#define MINIMUM_NUMBER_OF_BITS 0 
// Program LIMITATIONS : using integer values only in range of  to 2^31 -1

int toggle_nth_bit(int num,int n);
// Where num is the main number to be toggled and n is the bit's number from LSB


int main()
{
    int number,n;
    printf("Enter any number: ");
    scanf("%d",&number);
    printf("Enter nth bit to toggle (0-31): ");
    while(True){ // loop for making sure of appropirate user input
    scanf("%d",&n);
    if(n > MAX_NUMBER_OF_BITS || n < MINIMUM_NUMBER_OF_BITS){ 
        printf("Enter value in range (0-31)");
        continue; // if value is not valide return back to the begin 
        }
    break; // won't be seen until the input value is valid 
    }
    printf("Number before toggling %d bit: %d (in decimale)\n",n,number);
    printf("Number after  toggling %d bit: %d (in decimale)\n",n,toggle_nth_bit(number,n));
    return 0;
}
int toggle_nth_bit(int num,int n){
    return (num ^ (1 << n)); 
    /*As doing XOR the number is toggled (inverted)
    and to toggle the needed bit we will shift (1) in decimal with the (n) value in direction of MSB */
}
