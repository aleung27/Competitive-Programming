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

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main () {
    int n, maxMark, avg;
    scanf("%d %d %d", &n, &maxMark, &avg);

    vector<pair<ll, ll>> exams;
    int a, b;

    ll needs = (ll)avg*(ll)n;
    ll curr = 0;
    while(n--) {
        scanf("%d %d", &a, &b);
        exams.push_back({a,b});
        curr += a;
    }

    sort(exams.begin(), exams.end(), comp);
    ll essays = 0;
    int at = 0;

    while(curr < needs) {
        if(maxMark - exams[at].first > needs-curr) {
            essays += exams[at].second*(needs-curr);
            break;
        } else {
            essays += exams[at].second*(maxMark-exams[at].first);
            curr += maxMark-exams[at].first;
            at++;
        }
    }

    printf("%lld\n", essays);

    return 0;
}
