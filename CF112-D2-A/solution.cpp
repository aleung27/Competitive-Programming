#include <bits/stdc++.h>

using namespace std;

int main () {
    char str1[105] = "\0", str2[105] = "\0";
    scanf("%s %s", str1, str2);

    int i = 0;
    while(str1[i] != '\0') {
        if(tolower(str1[i]) < tolower(str2[i])) {
            printf("-1\n");
            return 0;
        } else if (tolower(str1[i]) > tolower(str2[i])) {
            printf("1\n");
            return 0;
        }

        i++;
    }

    printf("0\n");

    return 0;
}