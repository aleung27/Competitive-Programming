#include <bits/stdc++.h>

using namespace std;

int main() {
    int cals[4];
    for(int i = 0; i < 4; i++) {
        scanf("%d", cals + i);
    }

    int burnt = 0;
    char str[100005];

    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++) {
        burnt += cals[str[i] - '0' - 1];
    }

    printf("%d\n", burnt);

    return 0;
}