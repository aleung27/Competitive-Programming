#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main () {
    int dig, div;
    scanf("%d %d", &dig, &div);

    if(dig == 1 && div == 10) {
        printf("-1\n");
        return 0;
    } else if (div == 10) {
        printf("10");
        for(int i = 2; i < dig; i++) {
            printf("0");
        }
        printf("\n");

        return 0;
    }

    for(int i = 0; i < dig; i++) {
        i == dig-1 ? printf("%d\n", div) : printf("%d", div);
    }


    return 0;
}
