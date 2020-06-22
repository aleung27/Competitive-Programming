#include <bits/stdc++.h>

using namespace std;

int main () {
    int next;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            scanf("%d ", &next);
            if(next == 1) {
                printf("%d\n", abs(i-2)+abs(j-2));
                return 0;
            }
        }
    }

    return 0;
}