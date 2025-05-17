#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    __int128_t x = 1, y = 1;
    for (ll k = 0; k < K; k++) y *= 10;

    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        x *= a;
        if (x >= y) x = 1;
    }

    cout << (ll)x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
