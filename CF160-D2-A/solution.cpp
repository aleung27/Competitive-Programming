#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);

    int coins[n];
    int total = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
        total += coins[i];
    }

    sort(coins, coins + n, greater<int>());

    int min = 0;
    int count = 0;
    while(count <= total/2) {
        count += coins[min];
        min++;
    }

    printf("%d\n", min);

    return 0;
}