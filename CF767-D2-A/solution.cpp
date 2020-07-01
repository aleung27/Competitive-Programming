#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);

    pair<int, int> snacks[n];
    pair<int, int> next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next.first);
        next.second = i;
        snacks[i] = next;
    }

    sort(snacks, snacks + n, greater<pair<int, int>>());

    pair<int, int> largest = snacks[0];
    int counter = 0;
    for(int i = 0; i < n; i++) {

        if(snacks[i].second > largest.second) {
            for(; counter < snacks[i].second; counter++) {
                if(counter == largest.second){
                    for(int j = largest.first; j > snacks[i].first; j--) {
                        (j == snacks[i].first + 1) ? printf("%d\n", j) : printf("%d ", j);
                    }
                } else printf("\n");
            }

            largest = snacks[i];
        }
    }

    if (counter != n) {
        for(; counter < n-1; counter++) printf("\n");
        for(int i = largest.first; i > 0; i--) {
            (i == 1) ? printf("1\n") : printf("%d ", i);
        }
    }

    return 0;
}