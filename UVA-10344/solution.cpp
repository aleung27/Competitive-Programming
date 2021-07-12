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

bool operate(int curr, int at, vector<int>& nums) {
    // cout << "Current: " << curr << " at: " << at << endl;

    if (at == 4) {
        if (curr * nums[at] == 23 || curr - nums[at] == 23 ||
            curr + nums[at] == 23)
            return true;
        else
            return false;
    }
    if (operate(curr * nums[at], at + 1, nums) ||
        operate(curr - nums[at], at + 1, nums) ||
        operate(curr + nums[at], at + 1, nums))
        return true;
    return false;
}

int main() {
    FASTIO

    while (1) {
        int a;
        vector<int> nums;

        for (int i = 0; i < 5; i++) {
            cin >> a;
            nums.push_back(a);
        }

        if (!nums[0] && !nums[1] && !nums[2] && !nums[3] && !nums[4]) break;

        bool done = false;
        sort(nums.begin(), nums.end());
        do {
            if (operate(nums[0], 1, nums)) {
                done = true;
                cout << "Possible" << endl;
                break;
            }
        } while (next_permutation(nums.begin(), nums.end()));

        if (!done) cout << "Impossible" << endl;
    }
    return 0;
}
