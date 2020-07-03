#include <bits/stdc++.h>

using namespace std;

bool seen[105] = {false};
vector<int> order;

void top_sort(vector<int> adjlist[], int at) {
    seen[at] = true;

    for(int i = 0; i < adjlist[at].size(); i++) {
        int next = adjlist[at][i];
        if(!seen[next]) top_sort(adjlist, next);
    }

    order.push_back(at);
}

int main () {
    while(1) {
        int n, e;
        scanf("%d %d", &n, &e);
        memset(seen, false, sizeof(bool)*105);
        order.clear();

        if(n == 0 && e == 0) break;

        vector<int> adjlist[n + 1];
        int before, after;

        for(int i =0; i < e; i++) {
            scanf("%d %d", &before, &after);
            adjlist[before].push_back(after);
        }

        for(int i = 1; i <= n; i++) {
            if(!seen[i]) top_sort(adjlist, i);
        }

        for(int i = order.size() - 1; i >= 0; i--) {
            i == 0 ? printf("%d\n", order[i]) : printf("%d ", order[i]);
        }

    }

    return 0;
}