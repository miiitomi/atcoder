// https://atcoder.jp/contests/arc161/tasks/arc161_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<ll> V;
    for (ll i = 0; i <= 61; i++) {
        for (ll j = i+1; j <= 61; j++) {
            for (ll k = j+1; k <= 61; k++) {
                V.push_back((1LL << i) + (1LL << j) + (1LL << k));
            }
        }
    }
    sort(V.begin(), V.end());
    ll T;
    cin >> T;
    while (T--) {
        ll x;
        cin >> x;
        if (x < V[0]) {
            cout << -1 << endl;
        } else {
            auto iter = lower_bound(V.begin(), V.end(), x+1);
            iter--;
            cout << *iter << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    solve();
}
