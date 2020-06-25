#include <bits/stdc++.h>

using namespace std;

int main () {
    int length, distinct;
    scanf("%d %d", &length, &distinct);

    char str[length+1];
    for(int i = 0; i < length; i++) {
        str[i] = 'a' + (i % distinct);
    }

    str[length] = '\0';
    printf("%s\n", str);


    return 0;
}