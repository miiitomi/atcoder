// https://atcoder.jp/contests/abc073/tasks/abc073_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    for (ll &x : r) {
        cin >> x;
        x--;
    }
    vector<vector<ll>> dp(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) dp[i][i] = 0;
    for (int j = 0; j < M; j++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }

    for (int i = 0; i < N; i++) {
        vector<vector<ll>> ndp = dp;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                ndp[j][k] = min(ndp[j][k], dp[j][i] + dp[i][k]);
            }
        }
        swap(dp, ndp);
    }

    ll ans = INF;
    sort(r.begin(), r.end());
    do {
        ll tmp = 0;
        for (int i = 0; i < (int)r.size()-1; i++) {
            tmp += dp[r[i]][r[i+1]];
        }
        ans = min(ans, tmp);
    } while (next_permutation(r.begin(), r.end()));

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
