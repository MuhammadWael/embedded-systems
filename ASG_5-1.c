#include <stdio.h>
#define MAX_INTEGER_VALUE 2147483647 //biggest number that may be represented in integer form
#define MINIMUM_INTEGER_VALUE -2147483647 //smallest number that may be represented in integer form
#define GIVEN_ARRAY_DIMENSION 5 //the give number of array dimension

int main()
{
    //we assigened the greatest number to min variable to make sure user can't but any greater number
    //also the least number to the max variable to assure the correctness of output
    int max = MINIMUM_INTEGER_VALUE , min = MAX_INTEGER_VALUE;
    int arr_1[GIVEN_ARRAY_DIMENSION];// array decleration by the given name
    printf("Enter the five array's number\n");//to tell user to input the values
    for(int i = 0; i < GIVEN_ARRAY_DIMENSION; i++)//loop for assining the values to the array element
    {
        scanf("%d",&arr_1[i]);
    }
    printf("array is : ");
    for (int i = 0; i < GIVEN_ARRAY_DIMENSION; i++)//loop for determining the maximum and the minimum values from the given 
    {                                              
        if(arr_1[i] > max)
            max = arr_1[i];
        if (arr_1[i] < min)
            min = arr_1[i];
        printf("%d\t",arr_1[i]);// we used it for printing the values in series to avoid making extra loop with (n) complixty
    }
    printf("\n");
    for (int i = 0; i < GIVEN_ARRAY_DIMENSION; i++)//for printing the values of the Maximum and Minimum with their index
    {
        if(arr_1[i] == max)
            printf("the MAX number is %d in the index is %d\n",max,i);
        if (arr_1[i] == min)
            printf("the MIN number is %d in the index is %d\n",min,i);
    }
    return 0;
}