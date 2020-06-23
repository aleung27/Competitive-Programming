#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    int groups = 0;

    scanf("%d", &n);

    int last;
    scanf("%d", &last);
    groups++;

    int next;
    for(int i = 1; i < n; i++) {
        scanf("%d", &next);
        if(next != last) {
            groups++;
        }

        last = next;
    }

    printf("%d\n", groups);

    return 0;
}