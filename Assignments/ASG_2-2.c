
//code for determining if number is an armstrong or not
#include<stdio.h> //for scanf and printf functions
#include<math.h> //for pow function

void armstrong(int n); //to determine if the number is armstorng or not
int digits_count(int n); //to count the number of digits in given number

int main()
{
    int number;
    printf("Enter The number");
    scanf("%d",&number);
    armstrong(number);
    return 0;
}

int digits_count(int n){
    int count=0;
    while(n != 0)
    {
        n /= 10;    // divide the number by ten then increament the counter so it will count the number of digits in decimal 
        count++;
    }
    return count;
}
void armstrong(int n){
    
    int tester = n,sum = 0,temp;
    while(tester != 0){
        temp = tester % 10; // geting each number individualy then multiply by it self by the number of digits of the whole number
        sum += pow(temp,digits_count(n));
        tester /= 10;
    }
    if(sum == n) // if the sum of numbers is the same as the initial number so it's armstrong number 
        printf("%d is armstrong number",n);
    else
        printf("%d is Not armstrong number",n);
}



