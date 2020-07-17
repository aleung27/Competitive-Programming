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

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> adjlist[n+1];

    pair<int, int> nextPair;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &nextPair.first, &nextPair.second);
        adjlist[nextPair.first].push_back(nextPair.second);
        adjlist[nextPair.second].push_back(nextPair.first);
    }

    int grps = 0;

    while(1){
        unordered_set<int> rem;

        for(int i = 1; i <= n; i++) {
            if(adjlist[i].size() == 1) {
                rem.insert(i);
            }
        }

        if(rem.size() == 0) break;

        for(auto iter = rem.begin(); iter != rem.end(); iter++) {
            int val = adjlist[*iter][0];

            for(auto adjIter = adjlist[val].begin(); adjIter != adjlist[val].end(); adjIter++) {
                if (*adjIter == *iter) {
                    adjlist[val].erase(adjIter);
                    break;
                }
            }
            
            adjlist[*iter].clear();
        }

        grps++;
    }

    printf("%d\n", grps);

    return 0;
}
