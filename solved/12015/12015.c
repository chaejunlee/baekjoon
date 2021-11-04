#include <stdio.h>

int N = 0;
int A = 0;
int dp[1000001] = {0};
int size = -1;

int lowerBound(int start, int end, int item) {
    if (end - start > 0) {
        int mid = (start + end) / 2;

        if (dp[mid] < item) {
            return lowerBound(mid + 1, end, item);
        } else {
            return lowerBound(start, mid, item);
        }
    }
    return end;
}

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %lld", &A);
        if (A > dp[size]) {
            dp[++size] = A;
        } else {
            int low = lowerBound(0, size + 1, A);
            dp[low] = A;
        }
    }
    printf("%d\n", size + 1);

    return 0;
}