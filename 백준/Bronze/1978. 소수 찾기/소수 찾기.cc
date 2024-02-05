#include <iostream>
#include <cmath>
using namespace std;
int main(){
	
	int n;
	
	cin>>n; // n개의 갯수가 주어진다. 여기서 소수가 몇개인지 찾으시오
	
	int cnt=n;
	int number[100] ;
	
	for(int i =0; i<n; i++) {
		cin>>number[i];
		if( number[i] == 1) cnt--;
		
	}
	
	
	for(int i=0; i<n; i++) {
		
		for(int j=2 ; j<= sqrt(number[i]); j++){
			if( number[i] %j==0){
				cnt--;
				break;
			}
		}
	}
	

	
	
	
	cout<<cnt;
	
	
	
	
	
	
	
	
	
	
	
}