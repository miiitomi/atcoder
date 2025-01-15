// https://atcoder.jp/contests/abc063/tasks/arc075_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<bool> dp(1 + N*100, false);
    dp[0] = true;
    for (int i = 0; i < N; i++) {
        ll s;
        cin >> s;
        for (int j = N*100; j >= 0; j--) {
            if (!dp[j] || j+s > N*100) continue;
            dp[j+s] = true;
        }
    }
    ll ans = 0;
    for (int i = 0; i < N*100; i++) {
        if (i % 10 == 0 || !dp[i]) continue;
        ans = i;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
