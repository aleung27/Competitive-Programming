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
    int n, limit;
    string s;
    cin >> n >> limit;

    vector<string> placings;
    for (int i = 0; i < n; i++) {
        cin >> s;
        placings.push_back(s);
    }

    int longestStreak = -1;
    vector<int> streaks;
    for (int i = 65; i <= 122; i++) {
        if (i >= 91 && i <= 96) continue;

        char currentLetter = (char)i;
        int biggestStreak = -1;

        int streak = 0;
        for (const auto& placing : placings) {
            if (placing.substr(0, limit).find(currentLetter, 0) !=
                string::npos) {
                streak++;
                if (streak > biggestStreak) biggestStreak = streak;
            } else
                streak = 0;
        }

        if (biggestStreak < 1) continue;
        streaks.push_back(biggestStreak);
        if (biggestStreak > longestStreak) longestStreak = biggestStreak;
    }

    int counter = 0;
    for (const auto& e : streaks) {
        if (e == longestStreak) counter++;
    }

    cout << longestStreak << " " << counter << endl;

    return 0;
}
