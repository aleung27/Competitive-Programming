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

        vector<vector<bool>> students;
        for (int i = 0; i < n; i++) {
            vector<bool> availability;
            for (int j = 0; j < 5; j++) {
                cin >> next;
                if (next)
                    availability.push_back(true);
                else
                    availability.push_back(false);
            }

            students.push_back(availability);
        }

        bool done = false;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                int day1 = 0;
                int day2 = 0;
                int both = 0;
                bool error = false;

                for (const auto& A : students) {
                    if (A[i] && A[j])
                        both++;
                    else if (A[i])
                        day1++;
                    else if (A[j])
                        day2++;
                    else {
                        error = true;
                        break;
                    }
                }
                // cout << i << "&" << j << ": " << day1 << " " << day2 << " "
                //      << both << " " << error << endl;

                if (error) continue;

                int diff = abs(day1 - day2);

                if (!day1 && !day2) {
                    if (both % 2 == 0) {
                        done = true;
                        // cout << i << " " << j << endl;
                    }
                } else if (diff <= both && (both - diff) % 2 == 0) {
                    done = true;
                    // cout << i << " " << j << endl;
                }

                if (done) break;
            }
            if (done) break;
        }

        if (done)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
