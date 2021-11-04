#include <stdio.h>

int N = 0;
long long A = 0;
long long dp[1000001] = {0};
int size = -1;

int search(int n, long long item) {
    int start = 0;
    int end = n;

    int mid = n;
    while (end - start > 0) {
        mid = (start + end) / 2;

        if (dp[mid] < item) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return end;
}

int binsearch(int start, int end, int item) {
    if (end - start > 0) {
        int mid = (start + end) / 2;

        if (dp[mid] < item) {
            return binsearch(mid + 1, end, item);
        } else {
            return binsearch(start, mid, item);
        }
    }
    return end;
}

int main(void) {
    dp[0] = -1000000001;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %lld", &A);
        if (A > dp[size]) {
            dp[++size] = A;
        } else {
            int low = binsearch(0, size + 1, A);
            // printf("low: %d\n", low);
            // for (int j = 0; j <= size; j++) {
            //     printf("%d ", dp[j]);
            // }
            // printf("\n");
            dp[low] = A;
        }
    }
    // for (int j = 0; j <= size; j++) {
    //     printf("%d ", dp[j]);
    // }
    // printf("\n");
    printf("%d\n", size + 1);

    return 0;
}