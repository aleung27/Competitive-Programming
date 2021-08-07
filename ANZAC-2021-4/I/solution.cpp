
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a) * (b)).Y
#define DOTPROD(a, b) ((a).X * (b).X + (a).Y + (b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

template <class T>
T lcm(T a, T b) {
    return a * b / gcd<T>(a, b);
}

template <class T>
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

void fillMap(map<char, char>& consonantMap, map<char, string>& hardToEnding) {
    consonantMap.insert({'a', 'b'});
    consonantMap.insert({'b', 'b'});
    consonantMap.insert({'c', 'c'});
    consonantMap.insert({'d', 'd'});
    consonantMap.insert({'e', 'd'});

    for (int i = 102; i <= 105; i++) {
        consonantMap.insert({i, 'g'});
    }

    for (int i = 106; i <= 108; i++) {
        consonantMap.insert({i, 'k'});
    }

    for (int i = 109; i <= 111; i++) {
        consonantMap.insert({i, 'n'});
    }

    for (int i = 112; i <= 114; i++) {
        consonantMap.insert({i, 'p'});
    }

    for (int i = 115; i <= 122; i++) {
        consonantMap.insert({i, 't'});
    }

    hardToEnding.insert({'b', "ah"});
    hardToEnding.insert({'c', "ah"});
    hardToEnding.insert({'d', "ah"});
    hardToEnding.insert({'g', "ah"});
    hardToEnding.insert({'k', "oh"});
    hardToEnding.insert({'n', "oh"});
    hardToEnding.insert({'p', "oh"});
    hardToEnding.insert({'t', "uh"});
}

int main() {
    FASTIO
    string sentence;
    getline(cin, sentence);

    char hard[] = {'b', 'c', 'd', 'g', 'k', 'n', 'p', 't'};
    map<char, char> consonantMap;
    map<char, string> hardToEnding;
    fillMap(consonantMap, hardToEnding);

    string output = "";

    size_t pos = 0;
    string delim = " ";

    while ((pos = sentence.find(" "))) {
        string word = sentence.substr(0, pos);
        string transformed = "";
        bool uppercase = isupper(word[0]);

        if (uppercase) word[0] = tolower(word[0]);

        if (word.find("-") != string::npos) {
            size_t dashPos = 0;
            string dashDelim = "-";
            bool firstSyllable = true;

            while ((dashPos = word.find("-"))) {
                string syllable = word.substr(0, dashPos);

                if (firstSyllable) {
                    transformed += consonantMap[syllable[0]];
                    transformed += syllable.substr(1, string::npos);
                    firstSyllable = false;
                } else {
                    for (const auto& letter : syllable) {
                        bool replaced = false;
                        for (int i = 0; i < 8; i++) {
                            if (letter == hard[i]) {
                                transformed += transformed[0];
                                replaced = true;
                                break;
                            }
                        }
                        if (!replaced) transformed += letter;
                    }
                }
                if (dashPos == string::npos) break;
                word.erase(0, dashPos + dashDelim.length());
            }

            for (int i = 0; i < 8; i++) {
                if (transformed[transformed.length() - 1] == hard[i]) {
                    transformed += hardToEnding[hard[i]];
                    break;
                }
            }

            if (uppercase) transformed[0] = toupper(transformed[0]);
        } else {
            transformed += consonantMap[word[0]];
            transformed += word.substr(1, string::npos);

            for (int i = 0; i < 8; i++) {
                if (transformed[transformed.length() - 1] == hard[i]) {
                    transformed += hardToEnding[hard[i]];
                    break;
                }
            }

            if (uppercase) transformed[0] = toupper(transformed[0]);
        }

        output += transformed;
        output += " ";
        if (pos == string::npos) break;
        sentence.erase(0, pos + delim.length());
    }

    output.pop_back();
    cout << output << endl;

    return 0;
}
