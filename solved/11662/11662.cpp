#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define X first
#define Y second
using namespace std;
typedef pair<double, double> PAIR;

class Human {
   private:
   public:
    double startX;
    double startY;
    double endX;
    double endY;
    double dx;
    double dy;
    Human(PAIR start, PAIR end) {
        this->startX = start.X;
        this->startY = start.Y;
        this->endX = end.X;
        this->endY = end.Y;
        dx = end.X - start.X;
        dy = end.Y - start.Y;
    }
};

PAIR A, B, C, D;
double length = 0;

double getLength(Human A, Human B, double middle) {
    return sqrt(pow((A.startX - B.startX) + (A.dx - B.dx) * middle, 2) + pow((A.startY - B.startY) + (A.dy - B.dy) * middle, 2));
}

void closestDist(Human A, Human B, double left, double right) {
    double middle = (left + right) / 2;
    double lLen = getLength(A, B, left);
    double rLen = getLength(A, B, right);
    if (abs(lLen - rLen) < 1e-10) {
        length = getLength(A, B, middle);
        return;
    } else if (lLen > rLen) {
        closestDist(A, B, middle, right);
    } else {
        closestDist(A, B, left, middle);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(10);
    cin >> A.X >> A.Y >> B.X >> B.Y >> C.X >> C.Y >> D.X >> D.Y;
    Human Minho(A, B);
    Human Kangho(C, D);
    closestDist(Minho, Kangho, 0.0, 1.0);
    cout << length;
    return 0;
}