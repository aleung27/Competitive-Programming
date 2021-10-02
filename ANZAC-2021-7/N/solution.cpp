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

struct frac {
    ll numerator, denominator;
    ll from;
};

frac invalid = {-1, -1, 0};

bool isInvalid(frac state) {
    if (state.numerator == invalid.numerator &&
        state.denominator == invalid.denominator && state.from == invalid.from)
        return true;
    return false;
}

// Calcuate the frac if h hipsters come into train from state
// -1,-1 if not possible
frac calc(frac state, ll c, ll h, ll x, ll y, ll z) {
    if (isInvalid(state)) return invalid;
    ll num = max((ll)0, state.numerator - x);
    ll den = state.denominator + c;

    // double yDec = (double)y / 100;
    ll increase = (1 + z);  // increase/hipster
    // ll canAdd = ((double)den * (double)yDec - (double)num) / (double)increase
    // +
    //             EPS;  // amount of hipsters can add
    // canAdd++;
    // canAdd = max(canAdd, (ll)0);

    int left = 0, right = 10001;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (100 * (num + mid * increase) <= y * den)
            left = mid + 1;
        else
            right = mid - 1;
    }
    int canAdd = left;

    // int canAdd = 0;
    // while (100 * (num + canAdd * increase) <= y * den) {
    //     canAdd++;
    // }

    if (h > canAdd)
        return invalid;
    else {
        return {num + increase * h, den, 0};
    }
}

int main() {
    FASTIO
    ll stations, cap;
    ll c, h, x, y, z;
    cin >> stations >> cap;

    static frac dp[1005][10005];  // dp[i][j] - end of station i with j boarded

    for (int i = 0; i < stations; i++) {
        cin >> c >> h >> x >> y >> z;

        for (int j = 0; j < 10005; j++) {
            dp[i][j] = invalid;

            if (!i) {
                // Base case
                if (j <= h) dp[i][j] = calc({0, cap, 0}, c, j, x, y, z);
            } else {
                frac ans, best = {LLONG_MAX, 1, -1};
                for (int k = 0; k <= h; k++) {
                    if (j - k < 0) break;
                    ans = calc(dp[i - 1][j - k], c, k, x, y, z);
                    if (!isInvalid(ans) && ans.numerator < best.numerator) {
                        best = ans;
                        best.from = j - k;
                    }
                }

                if (best.numerator != LLONG_MAX) dp[i][j] = best;
            }

            // if (dp[i][j].numerator != -1)
            //     cout << " station " << i << " total " << j << " "
            //          << " from " << dp[i][j].from << " " <<
            //          dp[i][j].numerator
            //          << "/" << dp[i][j].denominator << endl;
        }
    }

    int ans = 0;
    for (int i = 0; i < 10005; i++) {
        if (!isInvalid(dp[stations - 1][i])) ans = i;
    }

    stack<int> vals;
    int from = ans;
    int currentStation = stations - 1;
    while (currentStation != -1) {
        vals.push(from - dp[currentStation][from].from);
        from = dp[currentStation][from].from;
        currentStation--;
    }

    while (!vals.empty()) {
        cout << vals.top();
        vals.pop();
        if (vals.empty())
            cout << endl;
        else
            cout << " ";
    }

    return 0;
}
