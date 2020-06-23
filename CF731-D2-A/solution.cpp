#include <bits/stdc++.h>

using namespace std;

int main() {
    char str[105];
    scanf("%s", str);

    int position = 'a';
    int i = 0;
    int rotations = 0;

    while(str[i] != '\0') {
        rotations += min(abs(position - str[i]), 26-abs(position - str[i]));
        position = str[i];
        i++; 
    }

    printf("%d\n", rotations);

    return 0;
}