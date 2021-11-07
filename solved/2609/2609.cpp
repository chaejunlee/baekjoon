#include <iostream>
using namespace std;

int myGcd(int a, int b)
{
    int c = b;
    while (b > 0)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int myLcm(int a, int b, int gcd)
{
    a /= gcd;
    b /= gcd;
    return a * b * gcd;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a = 0, b = 0;

    cin >> a >> b;

    int gcd = myGcd(a, b);
    int lcm = myLcm(a, b, gcd);

    cout << gcd << "\n" << lcm << endl;

    return 0;
}