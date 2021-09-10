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

void update(vector<ll>& segment, int pos, int value) {
    segment[pos] += value;
    for (pos /= 2; pos; pos /= 2) {
        segment[pos] = segment[2 * pos] + segment[2 * pos + 1];
    }
}

ll query(vector<ll>& segment, int pos, int n) {
    int left = n;
    ll sum = 0;
    while (left <= pos) {
        if (left % 2) sum += segment[left++];
        if (pos % 2 == 0) sum += segment[pos--];
        left /= 2;
        pos /= 2;
    }

    return sum;
}

int main() {
    FASTIO
    int n, q, next, a, b, val;
    cin >> n >> q;

    int segmentSize = 1;
    vector<ll> segment;
    for (segmentSize = 1; segmentSize < n;) segmentSize *= 2;
    segment.assign(2 * segmentSize, 0);

    vector<int> input;
    for (int i = 0; i < n; i++) {
        cin >> next;
        input.push_back(next);
    }

    for (int i = 0; i < n; i++) {
        update(segment, i + segmentSize,
               i ? input[i] - input[i - 1] : input[i]);
    }

    for (int i = 0; i < q; i++) {
        cin >> next;
        if (next == 1) {
            cin >> a >> b >> val;
            update(segment, a + segmentSize - 1, val);
            if (b + segmentSize < 2 * segmentSize)
                update(segment, b + segmentSize, -val);
            // for (const auto& e : segment) cout << e << endl;
        } else if (next == 2) {
            cin >> val;
            cout << query(segment, val + segmentSize - 1, segmentSize) << endl;
        }
    }

    return 0;
}
