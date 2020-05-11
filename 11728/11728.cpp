#include <iostream>
using namespace std;

int N, M;
int arr1[1000000], arr2[1000000];

void mergeSort(int* arr1, int* arr2) {
    int i = 0, j = 0;
    while (i < N && j < M) {
        if (arr1[i] > arr2[j]) {
            cout << arr2[j] << " ";
            j++;
        } else {
            cout << arr1[i] << " ";
            i++;
        }
    }
    if (i < N) {
        for (; i < N; i++)
            cout << arr1[i] << " ";
    }
    if (j < M) {
        for (; j < M; j++)
            cout << arr2[j] << " ";
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr1[i];
    for (int i = 0; i < M; i++)
        cin >> arr2[i];
    mergeSort(arr1, arr2);
    return 0;
}