#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n = 0;

    cin >> n;

    string s = "";
    
    if (n == 0)
        s = "0";

    while (n != 0)
    {
        if (n % (-2) != 0)
        {
            s = "1" + s;
            n = (n - 1) / (-2);
        }
        else
        {
            s = "0" + s;
            n = n / (-2);
        }
    }
    // while (s[0] != 0)
    // {
    //     s = s.substr(s[1], s[s.size() - 1]);
    // }
    cout << s;

    return 0;
}

// -13 1
//   7 1
//  -3 1 
//   2 0
//  -1 1 
//   1 1
//   0