#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int C;
    cin >> C;
    cout << fixed;
    cout.precision(3);
    while (C--) {
        int N;
        cin >> N;
        int sum = 0;
        
        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> v[i];
            sum += v[i];
        }
        
        int avg = sum / N;
        
        double ratio = 0.0f;
        
        for (int a : v) {
            if (a > avg) {
                ratio += (double) 1 / N;
            }
        }
        
        cout << ratio * 100 << "%\n";
    }
    return 0;
}
