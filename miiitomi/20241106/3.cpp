// https://atcoder.jp/contests/abc271/tasks/abc271_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, S;
    cin >> N >> S;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
    vector<vector<ll>> dp(N+1, vector<ll>(S+1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            if (dp[i][j] == -1) continue;
            if (j + a[i] <= S) dp[i+1][j+a[i]] = j;
            if (j + b[i] <= S) dp[i+1][j+b[i]] = j;
        }
    }
    if (dp[N][S] == -1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    string ans;
    int j = S;
    for (int i = N-1; i >= 0; i--) {
        int x = j - dp[i+1][j];
        if (x == a[i]) ans.push_back('H');
        else ans.push_back('T');
        j = dp[i+1][j];
    }
    reverse(ans.begin(), ans.end());
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
