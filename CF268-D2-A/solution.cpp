#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    pair<int, int> colours[n];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &colours[i].first, &colours[i].second);
    }

    int counter = 0;
    for(int i = 0; i < n; i++) {
        int home = colours[i].first;
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            
            if(colours[j].second == home) {
                counter++;
            }
        }
    }

    printf("%d\n", counter);

    return 0;
}