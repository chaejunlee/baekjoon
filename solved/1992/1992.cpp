#include <iostream>
using namespace std;

char screen[64][64] = { "\0" };

int check(int x, int y, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (screen[x][y] != screen[x + i][y + j])
				return 0;
		}
	}
	return 1;
}

void quadTree(int x, int y, int n) {
	if (n > 0)
	{
		printf("(");
		int mid = n / 2;
		if (check(x, y, mid))
		{
			printf("%c", screen[x][y]);
		}
		else quadTree(x, y, mid);
		if (check(x, y + mid, mid))
		{
			printf("%c", screen[x][y + mid]);
		}
		else quadTree(x, y + mid, mid);
		if (check(x + mid, y, mid))
		{
			printf("%c", screen[x + mid][y]);
		}
		else quadTree(x + mid, y, mid);
		if (check(x + mid, y + mid, mid))
		{
			printf("%c", screen[x + mid][y + mid]);
		}
		else quadTree(x + mid, y + mid, mid);
		printf(")");
	}
}

int main(void) {
	int n, digit;
	char temp[65] = "\0";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < n; j++) {
			screen[i][j] = temp[j];
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d", screen[i][j]);
		printf("\n");
	}*/
	if (check(0, 0, n))
	{
		printf("%c", screen[0][0]);
	}
	else quadTree(0, 0, n);
	return 0;
}