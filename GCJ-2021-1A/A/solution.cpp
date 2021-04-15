
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

    for (int a = 1; a <= t; a++) {
        int n;
        cin >> n;
        vector<string> nums;
        int ops = 0;

        for (int i = 0; i < n; i++) {
            string next;
            cin >> next;
            nums.push_back(next);
        }

        for (int i = 1; i < n; i++) {
            string curr = nums[i], prev = nums[i - 1];
            if (curr.length() > prev.length())
                continue;
            else if (curr.length() == prev.length()) {
                bool greater = false;
                for (int j = 0; j < prev.length(); j++) {
                    if (curr[j] > prev[j]) {
                        greater = true;
                        break;
                    } else if (curr[j] < prev[j]) {
                        break;
                    }
                }
                if (greater) continue;
            }

            for (int j = 0; j < prev.length(); j++) {
                if (curr.length() == j) {
                    // No chars left
                    string sub = prev.substr(j, string::npos);
                    bool invalid = true;
                    for (const auto& c : sub) {
                        if (c != '9') {
                            invalid = false;
                            break;
                        }
                    }

                    if (invalid) {
                        // we can only append 0's
                        ops += prev.length() + 1 - curr.length();
                        curr.append(
                            string(prev.length() + 1 - curr.length(), '0'));
                    } else {
                        // append substr + 1
                        for (int k = sub.length() - 1; k >= 0; k--) {
                            if (sub[k] != '9') {
                                sub[k]++;
                                break;
                            } else {
                                sub[k] = '0';
                            }
                        }

                        curr.append(sub);
                        ops += sub.length();
                    }
                    break;
                } else if (prev[j] == curr[j]) {
                    if (j == prev.length() - 1) {
                        ops++;
                        curr.push_back('0');
                    }
                    continue;
                } else {
                    // Append 0's to length
                    ops += prev.length() - curr.length();
                    curr.append(string(prev.length() - curr.length(), '0'));
                    // Add extra if digit was larger
                    if (prev[j] > curr[j]) {
                        curr.push_back('0');
                        ops++;
                    }
                    break;
                }
            }

            nums[i] = curr;
        }

        cout << "Case #" << a << ": " << ops << endl;
    }

    return 0;
}
