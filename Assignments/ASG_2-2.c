

#include<stdio.h> //for scanf and printf functions
#include<math.h> //for pow function

void armstrong(int n);
int digits_count(int n);

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
        count++;
        n /= 10;
    }
    return count;
}
void armstrong(int n){
    
    int tester = n,sum = 0,temp;
    while(tester != 0){
        temp = tester % 10;
        sum += pow(temp,digits_count(n));
        tester /= 10;
    }
    if(sum == n)
        printf("%d is armstrong number",n);
    else
        printf("%d is Not armstrong number",n);
}



