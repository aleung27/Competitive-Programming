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

struct val {
    string line;
    int count, pos;
};

bool mysort(const val& a, const val& b) {
    if (a.count == b.count) {
        return a.pos > b.pos;
    }
    return a.count > b.count;
}

int main() {
    int n, k;
    scanf("%d %d\n", &n, &k);

    string line;
    map<string, pair<int, int> > dict;
    int counter = 0;

    while (counter < 3 * n && getline(cin, line)) {
        if (dict.count(line)) {
            dict[line].first++;
            dict[line].second = counter;
        } else {
            dict.insert({line, {1, counter}});
        }
        counter++;
        // cout << counter << endl;
    }

    vector<val> book;
    for (const auto& e : dict) {
        book.push_back({e.first, e.second.first, e.second.second});
    }

    sort(book.begin(), book.end(), mysort);

    // for (const auto& e : book) {
    //     cout << e.line << " " << e.count << " " << e.pos << endl;
    // }

    for (int i = 0; i < k; i++) {
        if (i == book.size()) break;
        cout << book[i].line << endl;
    }

    return 0;
}
