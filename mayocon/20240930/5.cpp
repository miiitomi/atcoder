// https://atcoder.jp/contests/abc251/tasks/abc251_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll W;
    cin >> W;
    vector<ll> V;
    for (ll x = 1; x <= 99; x++) {
        V.push_back(x);
        V.push_back(x * 100);
        V.push_back(x * 10000);
    }
    V.push_back(1000000);
    cout << V.size() << "\n";
    for (ll x : V) cout << x << " ";
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
