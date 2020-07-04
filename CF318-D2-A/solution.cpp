#include <bits/stdc++.h>

using namespace std;

int main () {
    long long n, k;
    cin >> n >> k;

    n % 2 == 1 ? n = n/2 + 1 : n = n/2;
    k > n ? cout << (k-n)*2 << endl: cout << k*2-1 << endl;

    return 0;
}