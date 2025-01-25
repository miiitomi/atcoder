#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, X;
    cin >> N >> X;
    vector<vector<pair<ll,ll>>> V(3);
    for (int i = 0; i < N; i++) {
        ll v, a, c;
        cin >> v >> a >> c;
        v--;
        V[v].push_back({a, c});
    }
    vector<vector<ll>> dp(3, vector<ll>(X+1, -INF));
    for (int k = 0; k < 3; k++) {
        dp[k][0] = 0;
        for (auto &p : V[k]) {
            auto [a, c] = p;
            for (int x = X; x >= 0; x--) {
                if (x + c > X || dp[k][x] < 0) continue;
                dp[k][x+c] = max(dp[k][x+c], dp[k][x] + a);
            }
        }
    }

    ll left = 0, right = INF;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        ll tmp = 0;
        for (int k = 0; k < 3; k++) {
            ll x = INF;
            for (int j = 0; j <= X; j++) {
                if (dp[k][j] >= m) {
                    x = j;
                    break;
                }
            }
            tmp += x;
        }

        if (tmp <= X) left = m;
        else right = m;
    }
    cout << left << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
