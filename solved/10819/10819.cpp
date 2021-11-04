#include <iostream>
using namespace std;

int n;
int A[9] = {0};
int result = 0, temp = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void perm(int k) {
    if (k == n) {
        temp = 0;
        for (int i = 0; i < n - 1; i++) {
            temp += abs(A[i] - A[i + 1]);
        }
        result = max(temp, result);
        return;
    }
    for (int i = k; i < n; i++) {
        swap(&A[i], &A[k]);
        perm(k + 1);
        swap(&A[i], &A[k]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    perm(0);
    cout << result;
    return 0;
}