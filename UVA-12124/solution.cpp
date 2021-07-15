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

struct item {
    string type;
    int price, value;
};

struct itemWithName {
    string name;
    int price, value;
};

struct sc {
    bool operator()(const item& a, const item& b) {
        if (a.value == b.value) return a.type.compare(b.type);
        return a.value > b.value;
    }
};

struct mc {
    bool operator()(const itemWithName& a, const itemWithName& b) {
        if (a.price == b.price) {
            if (a.value == b.value) return a.name.compare(b.name);
            return a.value - b.value;
        }
        return a.price > b.price;
    }
};

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        int n, b;
        cin >> n >> b;
        map<string, priority_queue<itemWithName, vector<itemWithName>, mc>> map;
        priority_queue<item, vector<item>, sc> selected;

        for (int i = 0; i < n; i++) {
            string type, name;
            int price, value;
            cin >> type >> name >> price >> value;

            if (!map.count(type)) {
                map.insert(
                    {type,
                     priority_queue<itemWithName, vector<itemWithName>, mc>()});
            }
            map[type].push({name, price, value});
        }

        for (auto& e : map) {
            selected.push(
                {e.first, e.second.top().price, e.second.top().value});
            b -= e.second.top().price;
            e.second.pop();
        }

        // while (selected.size()) {
        //     auto next = selected.top();
        //     cout << next.type << " " << next.price << " " << next.value <<
        //     endl; selected.pop();
        // }

        while (1) {
            struct item top = selected.top();
            if (map[top.type].size()) {
                auto next = map[top.type].top();
                if (b + top.price - next.price > 0) {
                    if (next.value <= top.value) {
                        map[top.type].pop();
                    } else {
                        selected.pop();
                        selected.push({top.type, next.price, next.value});
                        b = b + top.price - next.price;
                        map[top.type].pop();
                    }
                } else
                    break;
            } else {
                break;
            }
        }

        cout << selected.top().value << endl;
    }

    return 0;
}
