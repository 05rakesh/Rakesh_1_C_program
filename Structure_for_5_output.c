#include <stdio.h>
struct student{
char name[50];
int age;
char gender[50];
char coll[100];
char dep[50];
};
int main(){
  struct student s1;
  printf("Enter name:");
  scanf("%s",s1.name);
  printf("Enter age:");
  scanf("%d",&s1.age);
  printf("Enter gender:");
  scanf("%s",s1.gender);
  printf("Enter College name:");
  scanf("%s",s1.coll);
  printf("Enter department:");
  scanf("%s",s1.dep);
  printf("Name:%s\nAge:%d\nGENDER:%s\nCOLLEGE:%s\nDEPARTMENT:%s", s1.name, s1.age,s1.gender,s1.coll,s1.dep);
  return 0;
}
