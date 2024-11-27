#include<stdio.h>
int main(){
  int n,sum=0;
  printf("enter the number of elements ");
  scanf("%d",&n);
  int arr[n];
  printf("enter the elements");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    sum += arr[i];
  }
printf("sum = %d",sum);
  return 0;
}