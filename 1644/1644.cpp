#include <bits/stdc++.h>
using namespace std;

long long minFactor[4000000];
vector<int> prime;

// 소수 구하고, 부분합 써서 푸는 문제 아님?

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    
    cin >> N;
    
    minFactor[0] = minFactor[1] = -1;
    for (long long i = 2; i < 4000000; i++)
        minFactor[i] = i;
    
    for (long long i = 2; i < 4000000; i++)
        if (minFactor[i] == i)
            for (long long j = i * i; j < 4000000; j += i)
                if (minFactor[j] == j)
                    minFactor[j] = i;

    for (int i = 2; i < 4000000; i++)
        if (minFactor[i] == i)
            prime.push_back(i);
    
    int low = -1;
    int high = 0;
    int ret = prime[high];
    int cnt = 0;
    while (high < prime.size() || low < high) {
        if (ret < N) {
            if (high == prime.size()) {
                break;
            }
            high++;
            ret += prime[high];
        }
        else if (ret > N) {
            low++;
            ret -= prime[low];
        }
        else {
            cnt++;
            high++;
            ret += prime[high];
        }
    }
    cout << cnt << "\n";
    
    return 0;
}
