#include <iostream>

using namespace std;

int dp[1001] = { 0 };

int tiles(int n) {
	if (n < 1) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (!dp[n - 1]) dp[n - 1] = tiles(n - 1);
	if (!dp[n - 2]) dp[n - 2] = tiles(n - 2);

	return (dp[n - 1] + dp[n - 2]) % 10007;
	// ���� ����.. �����ϴ� �����ڷ��� ũ�⸦ �Ѿư��� �Լ����� 10007�� �������� ���������
}

int main(void) {
	int n;
	cin >> n;
	cout << tiles(n) << endl;
	return 0;
}