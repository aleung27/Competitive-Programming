#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*b).Y
#define FASTIO ios::sync_with_stdio(false);

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    int n,m,k,q;
    scanf("%d %d %d %d", &n, &m, &k, &q);

    pair<int, int> coord;
    vector<int> wastes;
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &coord.first, &coord.second);
        wastes.push_back((coord.first-1)*m + coord.second);
    } 

    sort(wastes.begin(), wastes.end());

    for(int i = 0; i < q; i++) {
        scanf("%d %d", &coord.first, &coord.second);
        int total = (coord.first-1)*m + coord.second;

        int counter = 0;
        for(int j = 0; j < wastes.size(); j++) {
            if(wastes[j] == total) {
                counter = -1;
                break;
            } else if(wastes[j] > total) {
                break;
            } else {
                counter++;
            }
        }

        if(counter == -1) {
            printf("Waste\n");
            continue;
        } else {
            total -= counter;
            total = total % 3;
            string plant[3] = {"Grapes\n", "Carrots\n", "Kiwis\n"};
            cout << plant[total];
        }
    }

    return 0;
}
