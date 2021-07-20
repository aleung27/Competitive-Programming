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

struct node {
    int count;
    char value;
};

void calcValue(vector<node> &nodes, int i) {
    if (nodes[i].value == '?')
        nodes[i].count = nodes[2 * i + 1].count + nodes[2 * i + 2].count;
    else if (nodes[i].value == '1')
        nodes[i].count = nodes[2 * i + 2].count;
    else if (nodes[i].value == '0')
        nodes[i].count = nodes[2 * i + 1].count;
}

int main() {
    FASTIO
    int k;
    string s;
    int q;
    cin >> k >> s >> q;

    if (k == 1) {
        while (q--) {
            int a;
            char b;
            cin >> a >> b;
            b == '?' ? cout << "2" << endl : cout << "1" << endl;
        }
        return 0;
    }

    vector<node> nodes(s.length());  // teams as nodes 0 = root
    int map[s.length()];             // maps team# to node#

    int pos = pow(2, k) - 2;
    int counter = 0;
    for (int i = 0; i < k; i++) {
        int layer = pow(2, i);

        for (int j = 0; j < layer; j++) {
            node next = {s[pos + j] == '?' ? 2 : 1, s[pos + j]};
            nodes[counter] = next;
            map[pos + j] = counter;
            counter++;
        }

        pos -= pow(2, i + 1);
    }

    // Propogate values
    for (int i = pow(2, k - 1) - 2; i >= 0; i--) {
        calcValue(nodes, i);
    }

    // for (int i = 0; i < s.length(); i++) {
    //     cout << "Node " << i << ": " << nodes[i].count << " " <<
    //     nodes[i].value
    //          << endl;
    //     cout << map[i] << endl;
    // }

    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        p--;

        nodes[map[p]].value = c;
        // reset the value
        if (map[p] <= pow(2, k - 1) - 2) {
            calcValue(nodes, map[p]);
        } else {
            if (nodes[map[p]].value == '?')
                nodes[map[p]].count = 2;
            else
                nodes[map[p]].count = 1;
        }

        // propogate up
        for (int i = (map[p] - 1) / 2; i >= 0; i = (i - 1) / 2) {
            calcValue(nodes, i);
            if (i == 0) break;
        }

        cout << nodes[0].count << endl;
    }

    return 0;
}
