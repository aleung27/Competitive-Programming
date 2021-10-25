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

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        int n, next;
        cin >> n;
        vector<vector<int>> arrs;

        vector<int> start;
        for (int i = 0; i < n; i++) {
            cin >> next;
            start.push_back(next);
        }

        arrs.push_back(start);
        while (1) {
            int counts[n + 1];
            memset(counts, 0, sizeof(int) * (n + 1));

            for (int i = 0; i < n; i++) {
                counts[arrs[arrs.size() - 1][i]]++;
            }

            vector<int> newSeq;
            bool identical = true;
            for (int i = 0; i < n; i++) {
                newSeq.push_back(counts[arrs[arrs.size() - 1][i]]);
                if (newSeq[i] != arrs[arrs.size() - 1][i]) identical = false;
            }

            if (identical) break;
            arrs.push_back(newSeq);
        }

        int q, index, turn;
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> index >> turn;
            if (turn >= arrs.size()) turn = arrs.size() - 1;

            cout << arrs[turn][index - 1] << endl;
        }
    }

    return 0;
}
