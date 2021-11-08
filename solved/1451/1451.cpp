#include <cstdio>
int a[101][101];
long long s[101][101]; // 합
long long sum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
}
int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    // 합을 효율적으로 구하는 법
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (long long) a[i][j];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m - 2; i++) {
        for (int j = i + 1; j <= m - 1; j++) {
            long long r1 = sum(1, 1, n, i);
            long long r2 = sum(1, i + 1, n, j);
            long long r3 = sum(1, j + 1, n, m);
            if (ans < r1 * r2 * r3) {
                ans = r1 * r2 * r3;
            }
        }
    }
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            long long r1 = sum(1, 1, i, m);
            long long r2 = sum(i + 1, 1, j, m);
            long long r3 = sum(j + 1, 1, n, m);
            if (ans < r1 * r2 * r3)
                ans = r1 * r2 * r3;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m - 1; j++) {
            long long r1 = sum(1, 1, n, j);
            long long r2 = sum(1, j + 1, i, m);
            long long r3 = sum(i + 1, j + 1, n, m);
            if (ans < r1 * r2 * r3)
                ans = r1 * r2 * r3;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m - 1; j++) {
            long long r1 = sum(1, 1, i, j);
            long long r2 = sum(i + 1, 1, n, j);
            long long r3 = sum(1, j + 1, n, m);
            if (ans < r1 * r2 * r3)
                ans = r1 * r2 * r3;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m - 1; j++) {
            long long r1 = sum(1, 1, i, m);
            long long r2 = sum(i + 1, 1, n, j);
            long long r3 = sum(i + 1, j + 1, n, m);
            if (ans < r1 * r2 * r3)
                ans = r1 * r2 * r3;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m - 1; j++) {
            long long r1 = sum(1, 1, i, j);
            long long r2 = sum(1, j + 1, i, m);
            long long r3 = sum(i + 1, 1, n, m);
            if (ans < r1 * r2 * r3)
                ans = r1 * r2 * r3;
        }
    }
    printf("%lld", ans);
    return 0;
}