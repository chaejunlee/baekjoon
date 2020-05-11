#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n = 0;
    int b = 0;
    stack<long long> s;
    cin >> n >> b;
    while (n)
    {
        s.push(n % b);
        n /= b;
    }
    char c = '\0';
    while (!s.empty())
    {
        if (s.top() > 9) {
            c = 'A' + s.top() - 10;
            cout << c;
        }
        else
            cout << s.top();
        s.pop();
    }
}