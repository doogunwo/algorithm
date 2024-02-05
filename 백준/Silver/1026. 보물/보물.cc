#include <stdio.h>
#include <stdlib.h>
int main(){

	int T;
	int s;
	int sum=0;
	int arr1[50] ;
	int arr2[50] ;
	scanf("%d",&T);
	for(int i = 0; i < T ; i++)scanf("%d",&arr1[i]) ;
	for(int i = 0; i < T ; i++)scanf("%d",&arr2[i]) ;
	
	for(int i=0; i < T-1; i++) {
		
		for(int j = 0; j< T-1-i; j++){
			if( arr1[j] < arr1[j+1]) {
				s = arr1[j] ;
				arr1[j] = arr1[j+1] ;
				arr1[j+1] = s;
			}
			
		}
		for(int j = 0; j< T-1-i; j++){
			if( arr2[j] > arr2[j+1]) {
				s = arr2[j] ;
				arr2[j] = arr2[j+1] ;
				arr2[j+1] = s;
			}
			
			}
	}
		for ( int i = 0 ;i < T ;  i++) {
			sum = sum + arr1[i]*arr2[i];		}
	
	printf("%d",sum);
}
