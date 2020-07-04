#include<stdio.h>

int main()
{
    //declaring a stucture
    struct student
    {
        int stud_id;
        char stud_name[20];
        char stud_year[5];
        float stud_cgpa;
    };
    int n, i;
    printf("Enter no. of students: ");
    scanf("%d", &n);
    struct student s[n];
    //accepting student data
    for(i=1; i<=n; i++)
    {
        printf("\nEnter details of Student %d:",i);
        printf("Enter id: ");
        scanf("%d",&s[i].stud_id);
        printf("Enter name: ");
        scanf("%s", s[i].stud_name);
        printf("Enter year: ");
        scanf("%s",s[i].stud_year);
        printf("Enter CGPA: ");
        scanf("%f", &s[i].stud_cgpa);
    }

    //displaying student data:
    for(i=1; i<=n; i++)
    {
        printf("\nStudent ID: %d \nStudent Name: %s \nStudent Year: %s \nStudent CGPA:%f \n",s[i].stud_id,s[i].stud_name,s[i].stud_year,s[i].stud_cgpa);
    }
}