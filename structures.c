#include<stdio.h>
struct Student {
char name[50];
int roll;
float marks;
};
int main(){
  struct Student s1;
  printf("Enter the name of the student: ");
  scanf("%s",s1.name);
  printf("Enter the roll number of the student:");
  scanf("%d",&s1.roll);
    printf("Enter the marks of the student:");
  scanf("%f",&s1.marks);
  printf("\nStudent Details:\n");
  printf("Name:%s\nRoll Number:%d\nMARKS:%.2f\n",s1.name,s1.roll,s1.marks);
  return 0;
}