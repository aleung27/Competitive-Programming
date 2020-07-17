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
    bool (*seen)[8];
    int (*dist)[8];
};

int main () {
    FASTIO
    pair<int, int> moves[] = {{2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}};
    string start, end;

    while(cin >> start >> end) {
        pair<int, int> scoord, ecoord;
        scoord.first = start[0] - 97;
        scoord.second = start[1] - '0' - 1;
        ecoord.first = end[0] - 97;
        ecoord.second = end[1] - '0' - 1;

        queue<node> q;
        bool seen[8][8] = {{false}};
        int dist[8][8] = {{INT_MAX}};
        dist[scoord.first][scoord.second] = 0;
        seen[scoord.first][scoord.second] = true;

        node n = {scoord, seen, dist};
        q.push(n);
        int minDist;

        while(!q.empty()) {
            node curr = q.front();
            q.pop();
            curr.seen[curr.coord.first][curr.coord.second] = true;

            if(curr.coord == ecoord) {
                minDist = curr.dist[curr.coord.first][curr.coord.second];
                break;;
            }

            for(int i = 0; i < 8; i++) {
                int newFirst = curr.coord.first + moves[i].first;
                int newSecond = curr.coord.second + moves[i].second;
                if(newFirst < 0 || newFirst > 7 || newSecond < 0 || newSecond > 7 || curr.seen[newFirst][newSecond]) continue;
                curr.dist[newFirst][newSecond] = curr.dist[curr.coord.first][curr.coord.second] + 1;

                n = {{newFirst, newSecond}, curr.seen, curr.dist};
                q.push(n);
            }
        }

        cout << "To get from " << start << " to " << end << " takes " << minDist << " knight moves.\n"; 

    }



    return 0;
}
