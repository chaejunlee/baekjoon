#include <bits/stdc++.h>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define ll long long
#define PQ priority_queue
using namespace std;
bool smaller_second(pi a, pi b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
bool bigger_second(pi a, pi b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

// cmp
// going up: small < bigger (if small is small, then it comes faster)
// going down: small > bigger

int t = 0, N = 0, M = 0, K = 0;

double solve(double a, int b) {
    if (b == 2)
        return a * a;
    if (b == 1)
        return a;
    return solve(a, b / 2) * solve(a, b - (b / 2));
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double a;
    int b;
    cout.precision(9);
    cin >> a >> b;
    cout << solve(a, b);
}