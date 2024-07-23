// https://atcoder.jp/contests/abc182/tasks/abc182_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string N;
    cin >> N;
    ll k = N.size();
    ll ans = INF;
    for (ll s = 0; s < (1LL << k)-1; s++) {
        string M = N;
        ll tmp = 0;
        for (int i = k-1; i >= 0; i--) {
            if (s & (1LL << i)) {
                M.erase(M.begin()+i);
                tmp++;
            }
        }

        ll sum = 0;
        for (char &c : M) sum += (c - '0');
        if (sum % 3 == 0) ans = min(ans, tmp);
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
