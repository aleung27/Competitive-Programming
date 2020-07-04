#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main () {
    int n;
    scanf("%d", &n);
    unordered_map<string, int> score;

    string key1 = "", key2 = "";
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(score.count(s)) {
            score[s]++;
        } else score.insert({s, 1});

        if(key1 == "") key1 = s;
        else if(key2 == "" && key1 != s) key2 = s;
    }

    if(key2 == "") {
        cout << key1 << endl;
        return 0;
    }
    
    score[key1] > score[key2] ? cout << key1 << endl : cout << key2 << endl;


    return 0;
}
