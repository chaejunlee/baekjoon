#include <bits/stdc++.h>
using namespace std;

string dp[101][101];

string bigNumAdd(string num1, string num2) {
    long long sum = 0;
    string result;
    //1의 자리부터 더하기 시작한다
    while (!num1.empty() || !num2.empty() || sum) {
        if (!num1.empty()) {
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if (!num2.empty()) {
            sum += num2.back() - '0';
            num2.pop_back();
        }
        //다시 string 형태로 만들어 push_back
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    //1의 자리부터 result에 넣었으므로 뒤집어줘야한다
    reverse(result.begin(), result.end());
    return result;
}

string solve(int n, int m) {
    if (n == m || m == 0)
        return "1";

    string &result = dp[n][m];

    if (result != "")
        return result;

    result = bigNumAdd(solve(n - 1, m - 1), solve(n - 1, m));

    return result;
}

/*
1 1 1 1
1 2 1 1
1 3 3 1
1 4 6 4
1 5 10 10 5
*/

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    cout << solve(n, m);
}