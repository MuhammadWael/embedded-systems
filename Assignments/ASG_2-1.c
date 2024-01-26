//Code for doing operation on two numbers 
// declaring the needed library 
#include<stdio.h>
#define True 1
#define NUMBER_OF_OPERATIONS 4

int in_operations(char operation);
int main()
{
    double number_1,number_2,result;
    char op;
    printf("Enter 1st number : ");
    scanf("%lf",&number_1);
    while(True){ // infinte loop to assure the appropirate input 
        printf("Enter operator From(+,-,*,/) : \n");
        scanf(" %c",&op); // to prevent scaning white space we used (" %c") we could also use fgets
        if(in_operations(op)){
            break;
        }
    }
    printf("Enter 2nd number : ");
    scanf("%lf",&number_2);
    switch(op){
        case('+'):
            result = number_1 + number_2;
            break;
        case('-'):
            result = number_1 - number_2;
            break;
        case('*'):
            result = number_1 * number_2;
            break;
        case('/'):
            if(number_2 == 0) // if the second number is 0 so it will give invalid value 
            {
                printf("Can't divide by zero\n");
                return 0;
            }
            else if(number_1 == 0) // if the first number is 0 the answer would be zero (to prevent -0) 
            {
                result = 0;
                break;
            }
            result = number_1 / number_2;
            break;
    }
    printf("The result = %.2lf",result);
    return 0;
}

int in_operations(char operation){ // checking whether the operation in the supported one's or not 
    char operators[4] = {'+','-','*','/'};
    for(int i = 0;i < NUMBER_OF_OPERATIONS; i++){
        if(operators[i] == operation){
            return 1;
        }
    }
    return 0;
    }
    


