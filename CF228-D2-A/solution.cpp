#include <bits/stdc++.h>

using namespace std;

int main () {
    int next[4];
    unordered_set<int> seen;
    int needs = 0;

    for(int i = 0; i < 4; i++) {
        scanf("%d", &next[i]);
    }

    for(int i = 0; i < 4; i++) {
        if(!seen.count(next[i])) {
            seen.insert(next[i]);
            for(int j = i+1; j < 4; j++) {
                if (next[j] == next[i]) needs++;
            }
        }
    }

    printf("%d\n", needs);

    return 0;
}