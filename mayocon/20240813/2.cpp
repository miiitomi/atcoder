// https://atcoder.jp/contests/abc100/tasks/abc100_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll D, N;
    cin >> D >> N;
    vector<vector<ll>> V(3);
    for (ll x = 1; V[D].size() < N; x++) {
        ll k = 0;
        ll y = x;
        while (y % 100 == 0) {
            y /= 100;
            k++;
        }
        if (k <= 2) V[k].push_back(x);
    }
    cout << V[D].back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
