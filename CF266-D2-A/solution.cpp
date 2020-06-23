#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);

    int count = 0;
    char last;
    char next;
    scanf(" %c", &last);

    for(int i = 1; i < n; i++) {
        scanf("%c", &next);
        if(next == last) count++;
        last = next;
    }

    printf("%d\n", count);

    return 0;
}