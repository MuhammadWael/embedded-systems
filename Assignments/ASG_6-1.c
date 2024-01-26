#include <stdio.h>
#include <string.h>
#define NUMBER_OF_STUDENTS 5
#define LARGEST_NAME 20
#pragma pack(1)
struct Student
{
    char name[LARGEST_NAME];
    char age;
    char degree;
    char section;

};

struct Student get_student(void);
void print_student(struct Student *s,int size);


int main(){

    struct Student students[NUMBER_OF_STUDENTS];
    for(int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        printf("Enter The Data of Student Number %d\n",i+1);
        students[i] = get_student();
    }
    print_student(students,(sizeof(students)/sizeof(struct Student)));

    return 0;
}
void print_student(struct Student *s,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("The Data of Student Number %d is |\n",i+1);
        printf("Name    : %s\n",s[i].name);
        printf("Age     : %d\n",s[i].age);
        printf("Degree  : %d\n",s[i].degree);
        printf("Section : %d\n",s[i].section);
    }
    
}
struct Student get_student(void)
{
    struct Student s;
    char n[LARGEST_NAME];
    fflush(stdin);//to clear the buffer
    printf("Enter Student's name : ");
    scanf("%[^\n]*c",n); //*c mean read charecter and discard it
    strcpy(s.name,n);
    printf("Enter Student's age : ");
    scanf("%d",&s.age);
    printf("Enter Student's degree : ");
    scanf("%d",&s.degree);
    printf("Enter Student's section : ");
    scanf("%d",&s.section);
    return s;
}