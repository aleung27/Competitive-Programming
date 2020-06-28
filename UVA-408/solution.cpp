#include <bits/stdc++.h>

using namespace std;

int main () {
    while(1) {
        int step, mod;
        if(scanf("%d %d", &step, &mod) == EOF) break;

        int first = step % mod;
        int next = first;
        int i = 0;
        do {
            next = (next + step) % mod;
            i++;
        } while(next != first);

        i == mod ? printf("%10d%10d    Good Choice\n\n", step, mod) : printf("%10d%10d    Bad Choice\n\n", step, mod);
    }

    return 0;
}