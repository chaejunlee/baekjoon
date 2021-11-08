#include <iostream>
#include <vector>
using namespace std;
int N;
int A[500000];
long long cnt = 0;
void swap (int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}
// 7 6 5 / 4 3 2 1
// ^       ^
// cnt = 3 +
void merge(int start, int middle, int end) {
    vector<int> V;
    int i = 0, j = 0, len1 = middle - start, len2 = end - middle;
    while (i < len1 && j < len2) {
        if (A[start + i] > A[middle + j]) {
            cnt += len1 - i;
            V.push_back(A[middle + j++]);
        }
        else V.push_back(A[start + i++]);
    }
    while (i < len1)
        V.push_back(A[start + i++]);
    while (j < len2)
        V.push_back(A[middle + j++]);
    for (int i = start; i < end; i++)
        A[i] = V[i - start];
}
void mergeSort(int start, int end) {
    if (end == start + 1) return;
    if (end == start + 2) {
        if (A[start] > A[start + 1]) {
            cnt++;
            swap(A[start], A[start + 1]);
        }
        return;
    }
    int middle = (start + end) / 2;
    mergeSort(start, middle);
    mergeSort(middle, end);
    merge(start, middle, end);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    mergeSort(0, N);
    cout << cnt;
    return 0;
}