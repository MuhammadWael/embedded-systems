#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number of elements of array : ");
    scanf("%d",&n);
    int *array = (int*)malloc(sizeof(int)*n);//using memory allocation to store the array in heap
    
    for (int i = 0; i < n; i++)// loop to get the array's elements from user 
    {
        printf("Enter element number %d of array : ",i+1);// remind the user of the number of elemtn to enter
        scanf("%d",&array[i]);
    }
    printf("\nelements of the before reversing : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }
    int temp;
    for (int i = 0,j = n - 1; i < j; i++ , j--)//loop to swap elements of array from end to start and vice versa using temperaly variable 
    {//knowing that in odd the middle element will remain the same 
        temp = array[i];
        array[i] = array[j];// elements to be swaped
        array[j] = temp;
    }
    printf("\nelements of the after reversing : ");
    for (int i = 0; i < n; i++)//loop for printing elements after reversing the array
    {
        printf("%d ",array[i]);
    }
    
    free(array);// freeing the allocated memory
    return 0;
}