#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main () {
    ll n;
    cin >> n;

    n % 2 == 0 ? cout << n/2 << endl : cout << -1*(n+1)/2 << endl;


    return 0;
}
