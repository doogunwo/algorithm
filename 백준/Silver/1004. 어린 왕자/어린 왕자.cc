#include <stdio.h>

int main(){
	int  n,t; //n: 원갯수 t:테스트갯수
	int cnt;
	int x,y,r;
	int total;
	int x1,y1,x2,y2;
	
	scanf("%d",&t);

	 for(int i =0 ; i<t; i++) {
	 	total = 0;
	 	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	 	scanf("%d",&n);
	 	
	 	for(int i=0 ; i<n; i++){
	 		scanf("%d %d %d",&x,&y,&r);
	 		cnt=0;
            
	 		
	 	
	 		
			if((x-x1) *(x-x1) + (y-y1)*(y-y1) < r*r) cnt++;
			if((x-x2) *(x-x2) + (y-y2)*(y-y2) < r*r) cnt++;
			if(cnt ==1 )total++;	
		 }
        printf("%d\n",total);
	 }
    
}


