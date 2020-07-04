#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main () {
    vector<string> ans;
    string s;

    cin >> s;

    string word = "";
    for(int i = 0; i < s.length(); i++) {
        if(s.substr(i, 3) == "WUB") {
            if(word != "") ans.push_back(word);
            word = "";
            i = i + 2;
            continue;
        }

        word += s[i];
    }

    if(word != "") ans.push_back(word);
    for(int i = 0; i < ans.size(); i++) {
        i == ans.size()-1 ? cout << ans[i] << endl : cout << ans[i] << " ";
    }

    return 0;
}
