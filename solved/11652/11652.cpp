#include <iostream>
#include <algorithm>
using namespace std;

long long a[100001] = { 0 };
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	sort(a, a + n);
	int ans_cnt = 1;
	long long ans = a[0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] == a[i])
			cnt++;
		else
			cnt = 1;
		if (ans_cnt < cnt) {
			ans_cnt = cnt;
			ans = a[i];
		}
	}
	printf("%lld", ans);
	return 0;
}