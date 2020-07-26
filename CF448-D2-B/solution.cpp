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
    string s, t;
    cin >> s >> t;

    if(s.length() < t.length()) {
        printf("need tree\n");
    } else if(s.find(t) != string::npos) {
        printf("automaton\n");
    } else {
        bool done = false;

        for(;;) {
            int i = 0;

            for(int j = 0; j < s.length(); j++) {
                if(t[i] == s[j]) i++;
            }

            if(i == t.length()) done = true;
            break;
        }

        if(done) {
            printf("automaton\n");
            return 0;
        }

        unordered_map<char, int> shortdict, longdict;

        for(const auto& c : t) {
            if(shortdict.count(c)) {
                shortdict[c]++;
            } else shortdict.insert({c, 1});
        }

        for(const auto& c : s) {
            if(longdict.count(c)) longdict[c]++;
            else longdict.insert({c, 1});
        }

        bool ok = true;
        for(const auto& c : shortdict) {
            if(longdict.count(c.first) && longdict[c.first] >= c.second) {
                continue;
            }
            
            ok = false;
            break;
        }

        if(!ok) {
            printf("need tree\n");
        } else if(ok && s.length() == t.length()) {
            printf("array\n");
        } else {
            printf("both\n");
        }

    }


    return 0;
}
