#include <algorithm>
#include <iostream>

using namespace std;
int lcm(int n, int m){

    int r = n % m;
    if (r == 0) {
      return m;
    }
    return lcm(m, r);

}

int gcd(int n, int m,int v){
    return n*m / v;
}

int main(){
    int n,m;
    cin >> n >> m;
    
    int lcm_value = lcm(n,m);
    int gcd_value = gcd(n,m,lcm_value);

    cout << lcm_value << endl;
    cout << gcd_value;
}