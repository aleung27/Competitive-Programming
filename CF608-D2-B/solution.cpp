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
    string a, b;
    cin >> a >> b;

    ll ans = 0;
    int count1 = 0, count0 = 0;
    int start = 0, end = b.length()-a.length();

    for(int i = 0; i + a.length()-1 < b.length(); i++) {
        if(b[i] == '1') count1++;
        else count0++; 
    }

    a[0] == '1' ? ans += count0 : ans += count1;
    start++;
    end++;

    while(end < b.length()) {
        b[start-1] == '1' ? count1-- : count0--;
        b[end] == '1' ? count1++ : count0++;

        a[start] == '1' ? ans += count0 : ans += count1;
        start++;
        end++;
    }
    
    cout << ans << endl;
    return 0;
}
