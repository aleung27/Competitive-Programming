#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*(b)).Y
#define DOTPROD(a, b) ((a).X*(b).X + (a).Y+(b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

template <class T>
T modpow(T x, T n, T m) {
    if(n == 0) return 1 % m;
    ll u = modpow(x, n/2, m);
    u = (u*u)%m;
    if(n%2 == 1) u = (u*x)%m;
    return u;
}

int main () {
    FASTIO
    string s;
    int n;
    cin >> s >> n;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '9') continue;

        char largest = '.';
        int index;
        for(int j = i +1; j < min((int)s.length(), i + n + 1); j++) {
            if(s[j] > s[i] && int(s[j]) > int(largest)) {
                largest = s[j];
                index= j;
            } 
        }

        if(largest != '.') {
            n -= (index-i);
            s.insert(s.begin() + i, largest);
            s.erase(s.begin() + index + 1);
        }

        if(n == 0) break;
    }

    cout << s << endl;

    return 0;
}
