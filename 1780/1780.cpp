#include <iostream>
using namespace std;

int paper[2187][2187] = { {0} }, res[3] = { 0 };

int check(int x, int y, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (paper[x][y] != paper[x + i][y + j])
				return 1;
	res[paper[x][y] + 1]++;
	return 0;
}

void paperF(int x, int y, int n)
{
	if (n > 0)
		if (check(x, y, n))
		{
			int block = n / 3;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					paperF(x + block * i, y + block * j, block);
		}
}

int main(void)
{
	int input;
	cin >> input;
	for (int i = 0; i < input; i++)
		for (int j = 0; j < input; j++)
			cin >> paper[i][j];
	paperF(0, 0, input);
	for (int i = 0; i < 3; i++)
		printf("%d\n", res[i]);
	return 0;
}