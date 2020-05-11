#include <iostream>
using namespace std;

int main() {

    int N, K, mod = 1000000000;
    cin >> N >> K;

    //dp[k][n]=k개 더해서 n나오는 경우의 수
    long long dp[201][201] = { 0 };
    for (int n = 0; n <= N; n++) {
        dp[1][n] = 1; //0,1,2,3,...N
    }

    for (int k = 2; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            for (int l = 0; l <= n; l++) {
                dp[k][n] += dp[k - 1][l] % mod;
            }
            dp[k][n] %= mod;
        }
    }

    cout << dp[K][N] << endl;

    return 0;
}



//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//long long int dp[201][201] = { 0 };
//
//int main(void) {
//	int n = 0, k = 0;
//	cin >> n >> k;
//	for (int i = 1; i <= (200); i++) {
//		for (int j = 1; j <= i; j++) {
//			if (j == 1)
//				dp[i][j] = 1;
//			else if (j == 2)
//				dp[i][j] = i + 1;
//			else if (j == i)
//				dp[i][j] = (2 * dp[i - 1][j - 1] + dp[i][j - 1]) % 1000000000;
//			else
//				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
//
//		}
//	}
//	for (int i = 1; i <= 20; i++) {
//		for (int j = 1; j <= i; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << dp[n][k];
//	return 0;
//}