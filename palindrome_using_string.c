#include<sdtio.h>
#include<string.h>
int main(){
  char str[50],rev[50];
  printf("enter a string");
  scanf("%s",str);
  strcpy(rev,str);
  strrev(rev);
  if(strcmp(str,rev)==0){
    printf("the string is a palindrome\n");
  }
  else{
    printf("the string is not a palindrome\n");
    }
  return 0;
}