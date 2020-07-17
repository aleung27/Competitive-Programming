#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*b).Y
#define FASTIO ios::sync_with_stdio(false);

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

struct node {
    pair<int, int> coord;
    int dist;
};

int main () {
    pair<int, int> s, e;
    int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
    int dy[] = {0, 0 ,1, -1, -1, 1, -1, 1};
    scanf("%d %d %d %d", &s.first, &s.second, &e.first, &e.second);

    int n;
    scanf("%d", &n);
    set<pair<int, int>> coords;
    set<pair<int, int>> seen;

    int row, l, r;
    for(int i = 0; i < n ; i++) {
        scanf("%d %d %d", &row, &l, &r);
        for(int j = l; j <= r ; j++) {
            coords.insert({row, j});
        }
    }

    node start = {s, 0};
    queue<node> q;
    q.push(start);
    seen.insert(s);

    int dist = 0;
    bool done = false;
    while(!q.empty()) {
        node curr = q.front();
        q.pop();
        
        if(curr.coord == e) {
            dist = curr.dist;
            done = true;
            break;
        }

        for(int i = 0; i < 8; i++) {
            int nextF = curr.coord.first + dx[i];
            int nextS = curr.coord.second + dy[i];
            if(!seen.count({nextF, nextS}) && coords.count({nextF, nextS})) {
                node nextNode;
                nextNode.coord = {nextF, nextS};
                nextNode.dist = curr.dist + 1;
                seen.insert({nextF, nextS});
                q.push(nextNode);
            }
        }
    }

    done ? printf("%d\n", dist) : printf("-1\n");

    return 0;
}
