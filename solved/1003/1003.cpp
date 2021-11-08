/*
    0이 몇번 출력하는지랑 1이 몇번 출력되는 지 memoization 필요할 듯
        -> 구조체 배열 이용, index가 N의 정보를 저장
*/

#include <iostream>
#include <limits>

using namespace std;

typedef struct table {
    char done;
    int zero;
    int one;
} table;

int testCase[41] = { 0 };
table result[41];

void fib(int n) {
    if (result[n].done == 'y') return;
    if (n < 0) return;
    if (n == 0) {
        result[n].zero++;
        result[n].done = 'y';
        return;
    }
    else if (n == 1) {
        result[n].one++;
        result[n].done = 'y';
        return;
    }
    
    fib(n - 1);
    fib(n - 2);

    result[n].one = result[n - 1].one + result[n - 2].one;
    result[n].zero = result[n - 1].zero + result[n - 2].zero;
    result[n].done = 'y';
    return;
}

int main()
{
    for (int i = 0; i < 41; i++) {
        result[i].one = 0;
        result[i].zero = 0;
        result[i].done = 'n';
    }
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> testCase[i];
        fib(testCase[i]);
    }
    for (int i = 0; i < count; i++) {
        cout << result[testCase[i]].zero << " " << result[testCase[i]].one << endl;
    }
}