#include <bits/stdc++.h>
using namespace std;

int N, K;
string arr[15];
int arrMOD[16], arrLen[16];
long long cache[1<<15][100];
int power[51];

long long solve(int bit, int rem) {
    if (bit == ((1 << N) - 1)) {
        // K로 나눠진다.
        if (rem == 0) return 1;
        // K로 나눠지지 않는다.
        return 0;
    }
    
    long long& ret = cache[bit][rem];
    if (ret != -1) return ret;
    ret = 0;
    
    for (int i = 0; i < N; i++) {
        // 앞의 나머지가 가장 큰 차수가 된다.
        if ((1 << i) & bit) continue;
        
        int dividend = (rem * power[arrLen[i]] + arrMOD[i]) % K;
        
        ret += solve(bit | (1 << i), dividend);
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cin >> K;
    memset(cache, -1, sizeof(cache));
    sort(arr, arr + N);
    
    for (int i = 0; i < N; i++) {
        string temp = arr[i];
        int dividend = 0;
        for (int j = 0; j < temp.length(); j++) {
            dividend = dividend * 10 + temp[j] - '0';
            dividend %= K;
        }
        arrMOD[i] = dividend;
        arrLen[i] = temp.length();
    }
    
    power[0] = 1 % K;
    for (int i = 1; i < 51; i++) {
        power[i] = (power[i - 1] * 10) % K;
    }
    
    long long dividend = solve(0,0);
    long long divider = 1;
    if(dividend == 0){
        cout << "0/1"; return 0;
    }
    for(int i=1; i<=N; i++) divider *= i;
    long long g = __gcd(dividend, divider);
    dividend /= g; divider /= g;
    
    cout << dividend << "/" << divider << "\n";
    return 0;
}
