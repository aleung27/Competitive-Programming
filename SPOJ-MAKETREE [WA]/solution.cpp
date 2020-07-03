#include <bits/stdc++.h>

using namespace std;

int level[100005];

void dfs(vector<bool>& seen, vector<int>& parent, vector<int> adjlist[], int at) {
    seen[at] = true;

    for(int i = 0; i < adjlist[at].size(); i++) {
        int next = adjlist[at][i];
        
        if(parent[next] != 0) {
            if(level[at] >= level[next]) parent[next] = at;
        } else parent[next] = at;

        if(!seen[next]) {
            level[next] = max(level[at] + 1, level[next]);
            dfs(seen, parent, adjlist, next);
        }
    }
}

int main () {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<bool> seen(n+1, false);
    vector<int> adjlist[n+1];
    vector<int> parent(n+1, 0);
    memset(level, 0, 10005*sizeof(int));

    int e;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &e);

        int node;
        for(int j = 0; j < e; j++) {
            scanf("%d", &node);
            adjlist[i].push_back(node);
        }
    }

    for(int i = 1; i <=n; i++) {
        if(!seen[i]) dfs(seen, parent, adjlist, i);
    }

    int boss = 0;
    for(int i = 1; i <= n; i++) {
        if(parent[i] == 0) {
            if(boss == 0) {
                boss = i;
                printf("0\n");
            } else {
                printf("%d\n", boss);
            }
        } else {
            printf("%d\n", parent[i]);
        }
    }

    return 0;
}