#include <bits/stdc++.h>

using namespace std;

int main () {
    char str[105];
    int upper = 0, lower = 0;

    scanf("%s", str);

    int i = 0;
    while(*(str + i)) {
        tolower(str[i]) == str[i] ? lower++ : upper++;

        i++;
    }

    lower >= upper ? transform(str, str + i, str, ::tolower) : transform(str, str + i, str, ::toupper);
    printf("%s\n", str);

    return 0;
}