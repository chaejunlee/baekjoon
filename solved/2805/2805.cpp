#include <iostream>
using namespace std;

int N;
long long M, highest = 0;
long long tree[1000000];
long long ans = 0;

void cut(long long left, long long right) {
    if (left > right)
        return;
    long long middle = (left + right) / 2;
    long long trunk = 0;
    for (int i = 0; i < N; i++) {
        long long temp = tree[i] - middle;
        if (temp > 0)
            trunk += temp;
    }
    if (trunk >= M) {
        ans = max(ans, middle);
        cut(middle + 1, right);
    } else {
        cut(left, middle - 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        highest = max(highest, tree[i]);
    }
    cut(1, highest);
    cout << ans;
    return 0;
}