#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

bool cmp(char a, char b) {
    return a > b;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    bool countZero = false;
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
        if (s[i] == '0') {
            countZero = true;
        }
    }
    if (countZero) {
        if (sum % 3 == 0) {
            sort(s.begin(), s.end(), cmp);
            cout << s;
        }
        else {
            cout << -1;
        }
    } else {
        cout << -1;
    }

    return 0;
}