#include <string>
#include <vector>

using namespace std;

int solution(int num2) {
    long long num = num2;
    int answer = 0;
    while(1){
        
        if(num == 1){
            break;
        }   
        num%2 == 0 ? num=num/2 : num = num*3+1;
        answer++;

        if(answer >= 500){
            answer = -1;
            break;
        }
    }
    return answer;
}