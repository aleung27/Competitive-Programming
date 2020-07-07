#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*b).Y

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    int start = -1, end = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] != '.') {
            if(s[i] == 'R' && start == -1) start = i+1;
            else if(s[i] == 'L' && end == -1) end = i;

            if(s[i+1] == '.' && end == -1) end = i+2;
            if(s[i+1] == '.' && start == -1) start = i+1;
        }
    }

    cout << start << " " << end << endl;

    return 0;
}
