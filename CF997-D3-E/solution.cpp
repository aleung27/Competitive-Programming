#include <bits/stdc++.h>

using namespace std;

int n, m;
int seen[200005] = {false};
vector<int> adj[200005];

bool cycle = false;
bool edges = true;
int nodes = 0;

void dfs(int at, int from) {
    if (seen[at]) {
        cycle = true;
        return;
    }
    if (adj[at].size() != 2) edges = false;
    seen[at] = true;
    nodes++;

    for (const auto &node : adj[at]) {
        if (seen[node] && node != from) {
            cycle = true;
        }

        if (node != from) dfs(node, at);
    }
}

int main() {
    cin >> n >> m;

    int e1, e2;
    int counter = 0;
    for (int i = 0; i < m; i++) {
        cin >> e1 >> e2;
        adj[e1 - 1].push_back(e2 - 1);
        adj[e2 - 1].push_back(e1 - 1);
    }

    for (int i = 0; i < n; i++) {
        cycle = false;
        edges = true;
        nodes = 0;
        if (!seen[i]) dfs(i, INT_MAX);

        if (cycle && edges && nodes > 2) {
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}