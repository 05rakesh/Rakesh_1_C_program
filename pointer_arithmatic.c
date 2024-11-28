#include<stdio.h>
int main(){
int arr[] ={10,20,30};
int *ptr = arr;
printf("%d\n",*ptr);
ptr++;
printf("%d\n",*ptr);
}