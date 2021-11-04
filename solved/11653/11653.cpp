#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000000

int isNotPrime[SIZE] = {0};

void eratosthenes(void) {
    for (int i = 2; i * i < SIZE; i++)
        if (!isNotPrime[i])
            for (int j = i * i; j < SIZE; j += i)
                isNotPrime[j] = 1;
    isNotPrime[1] = 1;  
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    eratosthenes();
    long long n = 0;
    cin >> n;
    for (long long i = 2; i <= n; i++) {
        if (!isNotPrime[i])
            while ((n % i) == 0) {
                n /= i;
                cout << i << '\n';
            }
    }
    return 0;
}