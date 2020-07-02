#include <bits/stdc++.h>

using namespace std;

bool seen[105];
int colour[105];
bool cycle = false;

void dfs(int node, vector<int> adjlist[]) {
    if(seen[node]) return;
    seen[node] = true;

    for(auto u: adjlist[node]) {
        if(colour[u] == 0) {
            colour[u] = -1*colour[node];
            dfs(u, adjlist);
        } else if(colour[u] != -1*colour[node]){
            cycle = true;
            return;
        }
    }
}

int main () {
    int n, edges;
    scanf("%d %d", &n, &edges);
    memset(seen, false, 105);
    memset(colour, 0, 105);

    vector<int> adjlist[n+1];
    for(int i = 0; i < edges; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);    
    }

    int counter = 0;

    for(int i = 1; i <= n; i++) {
        if(!seen[i]) {
            cycle = false;
            colour[i] = 1;
            dfs(i, adjlist);

            if(cycle) {
                counter++;
            }
        }
    }
    
    if( (n-counter) % 2 != 0) counter++;
    printf("%d\n", counter);

    return 0;
}