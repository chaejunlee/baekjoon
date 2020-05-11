#include <iostream>
using namespace std;

long long n, k;
int cnt = 0;
int arr[10] = {0};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = n - 1; i >= 0; i--) {
        if (k / arr[i]) {
            cnt += k / arr[i];
            k %= arr[i];
        }
    }
    cout << cnt;
    return 0;
}