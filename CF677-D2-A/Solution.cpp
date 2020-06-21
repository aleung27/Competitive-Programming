#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, h;
    int next;
    int count = 0;

    scanf("%d %d", &n, &h);

    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        next <= h ? count++ : count += 2;
    } 

    printf("%d\n", count);

    return 0;
}