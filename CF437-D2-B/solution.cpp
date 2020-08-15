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

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main() {
    int sum, limit;
    scanf("%d %d", &sum, &limit);

    vector<pair<int, int>> nums;
    for (int i = 1; i <= limit; i++) {
        for (int j = 0; (1 << j) <= i; j++) {
            if (i & (1 << j)) {
                nums.push_back({i, 1 << j});
                break;
            }
        }
    }

    sort(nums.begin(), nums.end(), cmp);

    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        if (sum - nums[i].second >= 0) {
            ans.push_back(nums[i].first);
            sum -= nums[i].second;
        }

        if (!sum) break;
    }

    if (sum)
        printf("-1\n");
    else {
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < ans.size(); i++) {
            i == ans.size() - 1 ? printf("%d\n", ans[i])
                                : printf("%d ", ans[i]);
        }
    }

    return 0;
}
