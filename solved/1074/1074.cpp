#include <iostream>
#include <math.h>
using namespace std;

int input = 0, r = 0, c = 0, fInput = 0;
long int num = 0;

int zfunc(int x, int y, int n)
{
	if (x == r && y == c) {
		printf("%d", num);
		return 0;
	}
	if (n > 1)
	{
		// printf("x: %d y: %d n: %d num: %d\n", x, y, n, num);
		int mid = n / 2, xm = x + mid, ym = y + mid;
		if (r < xm && c < ym) {
			zfunc(x, y, mid);
			return 0;
		}
		if (r < xm && c >= ym) {
			num += pow(mid, 2);
			zfunc(x, y + mid, mid);
			return 0;
		}
		if (r >= xm && c < ym) {
			num += 2 * pow(mid, 2);
			zfunc(x + mid, y, mid);
			return 0;
		}
		if (r >= xm && c >= ym) {
			num += 3 * pow(mid, 2);
			zfunc(x + mid, y + mid, mid);
			return 0;
		}
	}
	return 0;
}

int main(void)
{
	cin >> input >> r >> c;
	fInput = (int) pow(2, input);
	//printf("f: %d", fInput);
	zfunc(0, 0, fInput);
	return 0;
}