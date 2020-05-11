#include <iostream>

using namespace std;

int table[1050000][2] = { { 0, 0 } };
int num = 0;

void hanoi(int n, int from, int to, int via) {
	if (n > 0) {
		hanoi(n - 1, from, via, to);
		table[num][0] = from;
		table[num][1] = to;
		num++;
		hanoi(n - 1, via, to, from);
	}
}

int main(void) {
	int n = 0;
	cin >> n;
	hanoi(n, 1, 3, 2);
	printf("%d\n", num);
	for (int i = 0; i < num; i++)
		printf("%d %d\n", table[i][0], table[i][1]);
	return 0;
}