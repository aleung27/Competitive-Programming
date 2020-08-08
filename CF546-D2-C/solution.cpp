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
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

int main() {
    int n, next;
    scanf("%d", &n);

    int cardsA, cardsB;
    queue<int> A, B;

    scanf("%d", &cardsA);
    for (int i = 0; i < cardsA; i++) {
        scanf("%d", &next);
        A.push(next);
    }

    scanf("%d", &cardsB);
    for (int i = 0; i < cardsB; i++) {
        scanf("%d", &next);
        B.push(next);
    }

    vector<pair<queue<int>, queue<int>>> states;
    states.push_back({A, B});

    bool loop = false;
    int counter = 0;
    while (!A.empty() && !B.empty()) {
        int currA = A.front();
        int currB = B.front();
        A.pop();
        B.pop();

        if (currA > currB) {
            A.push(currB);
            A.push(currA);
        } else {
            B.push(currA);
            B.push(currB);
        }
        counter++;

        for (const auto& p : states) {
            if (p.first == A && p.second == B) {
                loop = true;
                break;
            }
        }

        if (loop) break;
        states.push_back({A, B});
    }

    if (loop)
        printf("-1\n");
    else
        A.empty() ? printf("%d 2\n", counter) : printf("%d 1\n", counter);

    return 0;
}
