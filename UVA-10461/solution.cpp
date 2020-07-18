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

bool seen[505] = {false};

void dfs(int at, vector<int> adjlist[], vector<int> &deps) {
    seen[at] = true;

    for(int i = 0; i < adjlist[at].size(); i++) {
        if(!seen[adjlist[at][i]]) {
            dfs(adjlist[at][i], adjlist, deps);
        }
    }

    deps.push_back(at);
}

int main () {
    int v, e;
    int caseCounter = 1;

    while(1) {
        int totalWeight = 0;
        scanf("%d %d", &v, &e);
        if(v == e && v == 0) break;

        vector<int> adjlist[v+1];
        vector<int> reverseAdjlist[v+1];
        int weight[v+1];

        int nextWeight;
        for(int i = 1; i <= v; i++) {
            scanf("%d", &nextWeight);
            weight[i] = nextWeight;
            totalWeight += weight[i];
        } 

        pair<int, int> nextEdge;
        for(int i = 0; i < e; i++) {
            scanf("%d %d", &nextEdge.first, &nextEdge.second);
            adjlist[nextEdge.first].push_back(nextEdge.second);
            reverseAdjlist[nextEdge.second].push_back(nextEdge.first);
        }

        int q, nextQ;
        vector<int> deps;
        scanf("%d", &q);
        printf("Case #%d:\n", caseCounter);

        for(int i = 0; i < q; i++) {
            int shortest, longest;
            scanf("%d", &nextQ);

            deps.clear();
            memset(seen, false, (505)*sizeof(bool));

            dfs(nextQ, adjlist, deps);
            longest = totalWeight + weight[nextQ];
            shortest = 0;

            for(const auto& a: deps) {
                longest -= weight[a];
            }

            deps.clear();
            dfs(nextQ, reverseAdjlist, deps);

            for(const auto& a: deps) {
                shortest += weight[a];
            }

            printf("%d\n", longest-shortest);
        }

        caseCounter++;
        printf("\n");
    }


    return 0;
}
