#include <iostream>

int factorial(int n){
    if(n<=1){
        return 1;
    }
    return n * factorial(n-1);
}

int main(){
    int n,r;
    std::cin >>n >>r;
    int result = factorial(n) / (factorial(r) * factorial(n-r));
    std::cout << result;

}   