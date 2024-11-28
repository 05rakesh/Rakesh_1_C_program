#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,*arr;
  printf("enter the number of elements");
  scanf("%d",&n);
  arr=(int*)malloc(n*sizeof(int));
  if (arr==NULL){
    printf("memory not allocated");
    return 1;
  }
  printf("enter %d elements\n",n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  printf("the elements are");
  for(int i=0;i<n;i++){
    printf("%d",arr[i]);
  }
  free(arr);
  printf("after free %d",*arr);
  return 0;
  
  
  }
