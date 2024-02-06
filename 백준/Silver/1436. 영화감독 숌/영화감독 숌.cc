#include <iostream>
#include <string>
int main(){
    int n;

    std::cin >> n;
    int start = 666;
    int count = 0;


    while(true){
        std::string s = std::to_string(start);
        if(s.find("666") !=std::string::npos){
            ++count;
        }

        if(count == n){
            std::cout << start <<std::endl;
            break;
        }

        ++start;
    }
    
}