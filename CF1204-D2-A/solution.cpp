#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*b).Y
#define FASTIO ios::sync_with_stdio(false);

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    FASTIO
    string s;
    cin >> s;

    bool add = false;
    for(int i = 1; i < s.length(); i++) {
        if(s[i] - '0') add = true;
    }

    if(s.length() % 2 == 0) {
        cout << s.length()/2 << endl;
    } else {
        add ? cout << s.length()/2 + 1 << endl : cout << s.length()/2 << endl;
    }

    return 0;
}
