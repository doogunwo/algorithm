#include <stdio.h>

int main(){
	
	int A,B;
	scanf("%d %d",&A,&B);
	if( A>9){
		A=9;
	}
	if(B>9)	{
		B=9;
	}
		
	
	printf("%d",A-B);
}