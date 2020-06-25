#include <bits/stdc++.h>

using namespace std;

int main () {
    char str[1005];
    fgets(str, 1005, stdin);

    int i = 1;
    unordered_set<char> dict;

    while(str[i]) {
        if(str[i] != ',' && str[i] != '}' && str[i] != ' ' && str[i] != '\n') dict.insert(str[i]);

        i++;
    }

    printf("%ld\n", dict.size());

    return  0;
}