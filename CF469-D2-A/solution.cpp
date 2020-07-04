#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main () {
    unordered_set<int> levels;

    int n;
    scanf("%d", &n);

    int next;
    for(int i = 0; i < 2; i++) {
        int indices;
        scanf("%d", &indices);

        for(int j = 0; j < indices; j++) {
            scanf("%d", &next);
            levels.insert(next);
        }
    }
    levels.size() == n ? printf("I become the guy.\n") : printf("Oh, my keyboard!\n");


    return 0;
}