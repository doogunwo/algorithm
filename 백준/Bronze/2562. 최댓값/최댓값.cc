#include <stdio.h>

int main(){
  int max = 1, a, i;
  int A[10];
  
  for(i=0; i<9; i++){
    scanf("%d", &A[i]);
    if(max <= A[i]){
      max = A[i];
      a=i;
    }
  }
  printf("%d\n",max);
  printf("%d\n",a+1);
}