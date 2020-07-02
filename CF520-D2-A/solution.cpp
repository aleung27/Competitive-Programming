#include <bits/stdc++.h>

using namespace std;

int main () {
    unordered_set<char> alphabet;
    char s[105];
    int n;

    scanf("%d", &n);
    scanf("%s", s);
    for(const auto& c: s) {
        if(c == '\0') {
            break;
        } else {
            alphabet.insert(tolower(c));
        }
    }

    alphabet.size() == 26 ? printf("YES\n") : printf("NO\n");

    return 0;
}