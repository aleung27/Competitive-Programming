#include <bits/stdc++.h>

using namespace std;

int main () {
    unsigned int next;
    while(1) {
        scanf("%ud", &next);
        if (next == 0) break;

        (unsigned int)sqrt(next)*(unsigned int)sqrt(next) == next ? printf("yes\n") : printf("no\n");
    }

    return 0;
}