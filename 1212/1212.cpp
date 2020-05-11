#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s = "";
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        string c = "000";
        int temp = s[i] - '0';
        if (temp / 4)
            c[0] = '1';
        temp %= 4;
        if (temp / 2)
            c[1] = '1';
        temp %= 2;
        if (temp)
            c[2] = '1';
        if (i == 0) {
            cout << atoi(c.c_str());
        }
        else
            cout << c;
    }

    return 0;
}