#include <iostream>
using namespace std;

int getGCD(int a, int b)
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
    int n = 0, a = 0, b = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        int gcd = getGCD(a, b);
        cout << a * b / gcd << "\n";
    }
}