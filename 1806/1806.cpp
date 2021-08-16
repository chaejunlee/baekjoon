#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[100001];
    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int start = 0, end = 0, m = 100001;
    int psum = 0;
    while (end <= N) {
        if (psum < S) {
            psum += arr[end++];
        } else {
            m = min(m, end - start);
            psum -= arr[start++];
        }
    }
    if (m == 100001) cout << "0\n";
    else cout << m << "\n";
    
    return 0;
}
