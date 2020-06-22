#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);

    int blocks[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
    }

    sort(blocks, blocks + n);

    for (int i = 0; i < n; i++) {
        i == n-1 ? printf("%d\n", blocks[i]) : printf("%d ", blocks[i]);
    }

    return 0;
}