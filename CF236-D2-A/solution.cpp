#include <bits/stdc++.h>

using namespace std;

int main () {
    unordered_set<char> dict;
    char string[105];

    scanf("%s", string);

    int i = 0;
    int unique = 0;
    while(string[i]) {
        if(!dict.count(string[i])) {
            unique++;
            dict.insert(string[i]);
        }

        i++;
    }

    unique % 2 == 0 ? printf("CHAT WITH HER!\n") : printf("IGNORE HIM!\n");

    return 0;
}