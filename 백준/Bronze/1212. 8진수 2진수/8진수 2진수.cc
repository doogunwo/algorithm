#include <iostream>
#include <string>
using namespace std;

int main()
{
    string octal;
    cin >> octal;

    if(octal == "0")
        cout << 0 << '\n';

    string result;
    for (int i = 0; i < octal.length(); i++)
    {
        result += to_string((octal[i] - '0') / 4);
        result += to_string(((octal[i] - '0') % 4) / 2);
        result += to_string((((octal[i] - '0') % 4) % 2) / 1);
    }

    bool flag = false;
    for (int i = 0; i < result.length(); i++)
    {
        if (!flag)
        {
            if (result[i] == '1')
            {
                flag = true;
                cout << result[i];
            }
        }
        else
        {
            cout << result[i];
        }
    }
    cout << '\n';

    return 0;
}