#include <iostream>
#include <string>
using namespace std;

long long getGCD(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return getGCD(b, a % b);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a = 0, b = 0, result = 0;
    string s;

    cin >> a >> b;

    result = getGCD(a, b);

    for (int i = 0; i < result; i++)
        cout << "1";

    return 0;
}