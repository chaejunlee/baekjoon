#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    string result = "";
    for (int i = 0; i < input.size() % 3; i++)
        input = "0" + input;
    for (int i = 0; i < input.size(); i += 3)
    {
        char c = '0';
        if (input[i] == '1')
            c += 4;
        if (input[i + 1] == '1')
            c += 2;
        if (input[i + 2] == '1')
            c += 1;
        cout << c;
    }

    return 0;
}