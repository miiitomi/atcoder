// https://atcoder.jp/contests/abc058/tasks/abc058_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string o, e;
    cin >> o >> e;

    for (int i = 0; i < max((int)o.size(), (int)e.size()); i++) {
        cout << o[i];
        if (i < (int)e.size()) cout << e[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
