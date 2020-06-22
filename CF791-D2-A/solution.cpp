#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int count = 0;

    while(a <= b) {
        count++;
        a *= 3;
        b *= 2;
    }

    printf("%d\n", count);

    return 0;
}