#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);

    int presents[n + 1];
    int next;
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        presents[next] = i + 1;
    }

    for(int i = 1; i <= n; i++) {
        i == n ? printf("%d\n", presents[i]) : printf("%d ", presents[i]);
    }

    return 0;
}