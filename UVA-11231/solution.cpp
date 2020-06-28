#include <bits/stdc++.h>

using namespace std;

int main () {
    while(1) {
        int r, c, colour;
        scanf("%d %d %d", &r, &c, &colour);
        if(r == 0 && c == 0) break;

        int total = (r-7) * (c-7);
        colour == 1 ? total = (int)ceil((double)total/2) :  total /= 2;
        printf("%d\n", total);
    }

    return 0;
}