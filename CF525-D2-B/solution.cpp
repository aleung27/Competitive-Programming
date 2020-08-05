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
    int n, a;
    cin >> s >> n;

    vector<int> swappings;
    for(int i = 0; i < n; i++) {
        cin >> a;
        swappings.push_back(a);
    }

    sort(swappings.begin(), swappings.end());

    for(int i = 0; i < swappings.size(); i += 2) {
        int start = swappings[i];
        int end;

        if(i == swappings.size()-1) end = INT_MAX;
        else end = swappings[i+1];

        for(int j = start; j < min((int)s.length()/2 + 1, end); j++) {
            swap(s[j-1], s[s.length()-j]);
        }
    }

    cout << s << endl;

    return 0;
}
