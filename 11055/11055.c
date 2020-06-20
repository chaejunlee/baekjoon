#include <stdio.h>
#include <stdlib.h>

int n = 0;
int A[1001] = {0};
int dp[1001] = {0};
int maxx = 1;

int main(void) {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &A[i]);
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i] = ((dp[j] + 1) >= (dp[i])) ? (dp[j] + 1): (dp[i]);
                if (maxx < dp[i])
                    maxx = dp[i];
            }
        }
    }
    printf("%d", maxx);
    return 0;
}