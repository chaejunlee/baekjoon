#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

int a[1000 + 1];
int dp[1000 + 1];

int main()
{
    int tc; //<1000
    scanf("%d", &tc);

    for (int i = 0; i < tc; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < tc; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }
    int result = dp[0];
    for (int i = 0; i < tc; i++)
        if (result < dp[i]) result = dp[i];

    for (int i = 0; i < tc; i++)
        printf("%d ", dp[i]);
    printf("%d\n", result);

}