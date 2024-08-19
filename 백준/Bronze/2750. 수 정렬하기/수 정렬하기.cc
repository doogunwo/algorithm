#include <stdio.h>
int main(){
	int i,j,tmp;
	int n;
	int a[1001]={0};
	
	scanf("%d",&n);
	for( i= 0; i<n; i++){
		scanf("%d",&a[i]);
	}
	for(i=0; i<n; i++) {
		
		for(j=0; j<n-1 ; j++) {
			
			if(a[j+1] < a[j]) {
				tmp = a[j+1];// a[j+1] <a[j] 이면  
				a[j+1] =a[j];
				a[j] = tmp;
			}
		}
}
for(int i=0; i< n; i++) {
	printf("%d\n",a[i]);

}
return 0;}		
	
	
	
	
	
	
	
