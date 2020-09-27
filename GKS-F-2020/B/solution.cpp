
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a) * (b)).Y
#define DOTPROD(a, b) ((a).X * (b).X + (a).Y + (b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

template <class T>
T lcm(T a, T b) {
    return a * b / gcd<T>(a, b);
}

template <class T>
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int a = 1; a <= t; a++) {
        int n, t;
        scanf("%d %d", &n, &t);

        vector<pair<int, int>> segments;
        int s, e;
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &s, &e);
            segments.push_back({s, e});
        }

        sort(segments.begin(), segments.end(), comp);
    
        int robots = 0;
        int end = 0;
        for(int i = 0; i < segments.size(); i++) {
            if(end >= segments[i].second) {
                continue;
            } else if(end < segments[i].second) {
                if(end <= segments[i].first) {
                    int needed = (segments[i].second-segments[i].first)/t;
                    if((segments[i].second-segments[i].first) % t != 0) needed++;
                    end = segments[i].first + (t*needed);
                    robots += needed; 
                } else {
                    int needed = (segments[i].second-end)/t;
                    if((segments[i].second - end) % t != 0) needed++;
                    end = end + (t*needed);
                    robots += needed;
                }
            }
        }

        printf("Case #%d: %d\n", a, robots);
    }

    return 0;
}
