#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    int values[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    for(int i = 0; i < n; i++) {
        if(i == 0) printf("%d %d\n", values[i+1]-values[i], values[n-1]-values[i]);
        else if (i == n-1) printf("%d %d\n", values[i] - values[i-1], values[i] - values[0]);
        else {
            printf("%d %d\n", min(values[i]-values[i-1], values[i+1]-values[i]), max(values[n-1] - values[i], values[i] - values[0]));
        }
    }

    return 0;
}