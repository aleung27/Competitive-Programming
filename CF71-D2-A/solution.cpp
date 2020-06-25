#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d ", &n);
    char line[105];

    for(int i = 0; i < n; i++) {
        scanf("%s", line);
        strlen(line) <= 10 ? printf("%s\n", line) : printf("%c%ld%c\n", line[0], strlen(line)-2, line[strlen(line)-1]);
    }

    return 0;
}