#include <string>
#include <iostream>
#include <stdlib.h>
#include <cctype> 
using namespace std;

bool solution(string s)
{   
    bool answer = true;
    int P =0;
    int Y =0;
    for(int i =0; i< s.length(); i++){
        char ch = tolower(s[i]);
        if (ch== 'p'){
            P = P+1;
        }
        if (ch == 'y'){
            Y = Y+1;
        }
    }
    if(P != Y){
        answer = false;
    }
    return answer;
}
