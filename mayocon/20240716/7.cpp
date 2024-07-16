// https://atcoder.jp/contests/abc289/tasks/abc289_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void p(pair<ll,ll> p) {
    cout << p.first << " " << p.second << "\n";
}

void solve() {
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (sx%2 != tx%2 || sy%2 != ty%2) {
        cout << "No\n";
        return;
    }

    vector<pair<ll,ll>> V;
    if (a == b) {
        if (sx != tx) {
            sx = 2*a - sx;
            sy = 2*c - sy;
            V.push_back({a, c});
        }
        if (sx != tx) {
            cout << "No\n";
            return;
        }
    }
    if (c == d) {
        if (sy != ty) {
            sx = 2*a - sx;
            sy = 2*c - sy;
            V.push_back({a, c});
        }
        if (sy != ty) {
            cout << "No\n";
            return;
        }
    }
    if (a == b && c == d) {
        if (sx != tx || sy != ty) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    for (auto q : V) p(q);
    while (sx < tx) {
        p({a, c});
        p({a+1, c});
        sx += 2;
    }
    while (sx > tx) {
        p({a+1, c});
        p({a, c});
        sx -= 2;
    }
    while (sy < ty) {
        p({a, c});
        p({a, c+1});
        sy += 2;
    }
    while (sy > ty) {
        p({a, c+1});
        p({a, c});
        sy -= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
