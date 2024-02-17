#include <iostream>
#include <vector>
using namespace std;


int main(){
    
    int start, end;

    cin >> start >> end;

    vector<bool> isPrime(end + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= end; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= end; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = start; i <= end; ++i) {
        if (isPrime[i]) {
            cout << i << '\n';
        }
    

}
}