#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll M;
    cin >> M;
    vector<ll> V;
    for (ll a = 0; a <= 10; a++) {
        ll k = M%3;
        for (ll i = 0; i < k; i++) V.push_back(a);
        M /= 3;
    }
    cout << V.size() << "\n";
    for (ll a : V) cout << a << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
