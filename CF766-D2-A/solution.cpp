#include <bits/stdc++.h>

using namespace std;

int main () {
    char a[100005], b[100005];

    scanf("%s %s", a, b);

    !strcmp(a,b) ? printf("-1\n") : printf("%d\n", max((int)strlen(a), (int)strlen(b)));

    return 0;
}