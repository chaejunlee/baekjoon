#include <iostream>
using namespace std;

long long K, N, MAX = 0;
long long cord[10001] = {0};
long long ans = 0;

void cut(long long left, long long right) {
    if (left > right) {
        return;
    }
    long long mid = (left + right) / 2;
    long long count = 0;
    for (long long i = 0; i < K; i++)
        count += cord[i] / mid;
    if (count >= N) {
        ans = max(ans, mid);
        cut(mid + 1, right);
    }
    else {
        cut(left, mid - 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    for (long long i = 0; i < K; i++) {
        cin >> cord[i];
        MAX = max(MAX, cord[i]);
    }
    cut(1, MAX);
    cout << ans;
    return 0;
}