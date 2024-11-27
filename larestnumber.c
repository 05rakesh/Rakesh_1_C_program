#include<stdio.h>
int largest(int a,int b,int c){
if(a>=b && a>=c) return a;
if(b>=a && b>=c) return b;
return c;
}
int main(){
  int x,y,z;
  printf("enter the three numbers");
  scanf("%d %d %d",&x,&y,&z);
  printf("largest = %d\n",largest(x,y,z));
  return 0;
}

