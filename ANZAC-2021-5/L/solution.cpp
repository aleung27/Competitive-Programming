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

int total = 0;

void dfs(int at, string& w, int index, vector<set<char>>& capitals,
         vector<bool> seen) {
    seen[at] = true;

    if (capitals[at].count(w[index])) {
        if (index == w.length() - 1) {
            total++;
            return;
        }

        for (int i = 0; i < capitals.size(); i++) {
            if (!seen.at(i) && capitals[i].count(w[index + 1]))
                dfs(i, w, index + 1, capitals, seen);
        }
    } else
        return;
}

int main() {
    FASTIO
    int n, w;

    cin >> n >> w;

    vector<set<char>> capitals;
    for (int i = 0; i < n; i++) {
        string s;
        set<char> caps;
        cin >> s;

        for (int i = 0; i < s.length(); i++) {
            if (isupper(s[i])) caps.insert(s[i]);
        }

        capitals.push_back(caps);
    }

    for (int i = 0; i < w; i++) {
        string word;
        cin >> word;
        total = 0;

        if (word.length() != n) {
            cout << "0" << endl;
            continue;
        }
        for (int j = 0; j < word.length(); j++)
            dfs(j, word, 0, capitals, vector<bool>(10, false));

        // int dp[n][word.length()];
        // for (int j = 0; j < word.length(); j++) {
        //     for (int i = 0; i < n; i++) {
        //         if (capitals[i].count(word[j])) {
        //             if (j) {
        //                 int sum = 0;
        //                 for (int k = 0; k < n; k++) {
        //                     if (k == i) continue;
        //                     sum += dp[k][j - 1];
        //                 }
        //                 dp[i][j] = sum;
        //             } else {
        //                 dp[i][j] = 1;
        //             }
        //         } else {
        //             dp[i][j] = 0;
        //         }
        //     }
        // }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < word.length(); j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     ans = max(ans, dp[i][word.length() - 1]);
        // }
        // cout << ans << endl;

        cout << total << endl;
    }

    return 0;
}
