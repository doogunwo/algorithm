#include <iostream>
#include <algorithm>

using namespace std;

    
int step[301];
int arr[301];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        step[i] = a;
    }

    arr[1] = step[1];
    arr[2] = step[1] + step[2];
    arr[3] = step[3] + max(step[1], step[2]);
    

    for(int i = 4; i <= N; i++)
    {
        arr[i] = step[i] + max(step[i - 1] + arr[i - 3], arr[i - 2]);
    }

    cout << arr[N];
    return 0;
}
