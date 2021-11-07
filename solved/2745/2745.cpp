#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s = "";
    int b;
    cin >> s >> b;
    long long decimal = 0, m = 1;

    while (s.size())
    {
        if (s[s.size() - 1] >= 'A')
            decimal += (s[s.size() - 1] - 'A' + 10) * m;
        else
            decimal += (s[s.size() - 1] - '0') * m;
        s = s.substr(0, s.size() - 1);
        m *= b;
    }
    cout << decimal;

    return 0;
}