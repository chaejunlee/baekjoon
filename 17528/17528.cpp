#include <bits/stdc++.h>
using namespace std;

int N, A[251], B[251];
int cache[251][62501][2];

// k까지 작업에 대해 machine이 작업해야 할 시간이 t일 때
// 나머지 작업들을 완료하기 위해 걸리는 시간의 최솟값
int solve(int k, int t, int machine) {
    // k가 마지막에 다다르면 쌓인 t를 리턴
    if (k == N) return t;
    
    int& ret = cache[k][t][machine];
    if (ret != -1) return ret;
    ret = 987654321;
    
    if (machine == 0) {
        // machine A에 계속 할 일 쌓기
        ret = min(ret, solve(k + 1, t + A[k], 0));
        // machine B한테 시킬 작업 체크
        // machine A에 쌓인 작업의 시간보다 B[k]의 작업 시간이 작다면 (t > B[k])
        // B에게 시키고 끝날 때 남는 시간을 계속 A에게 넘겨준다.
        if (t > B[k]) ret = min(ret, solve(k + 1, t - B[k], 0) + B[k]);
        // machine A에 쌓인 작업의 시간보다 B[k]의 작업 시간이 크다면 (t <= B[k])
        // B에게 시키고 끝날 때 남는 시간을 B에게 넘겨준다.
        else ret = min(ret, solve(k + 1, B[k] - t, 1) + t);
    } else {
        // vice versa
        if (t > A[k]) ret = min(ret, solve(k + 1, t - A[k], 1) + A[k]);
        else ret = min(ret, solve(k + 1, A[k] - t, 0) + t);
        ret = min(ret, solve(k + 1, t + B[k], 1));
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    
    memset(cache, -1, sizeof(cache));
    cout << solve(0, 0, 0) << "\n";

    
    return 0;
}