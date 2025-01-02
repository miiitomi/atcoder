// https://atcoder.jp/contests/typical90/tasks/typical90_k
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct Task {
    ll d, c, s;
};

void solve() {
    ll N;
    cin >> N;
    vector<Task> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i].d >> T[i].c >> T[i].s;
    }
    sort(T.begin(), T.end(), [](const Task &l, const Task &r) {return l.d < r.d;});
    vector<vector<ll>> dp(N+1, vector<ll>(5001, 0));
    for (int i = 0; i < N; i++) {
        dp[i+1] = dp[i];
        for (int j = 0; j + T[i].c <= T[i].d; j++) {
            dp[i+1][j+T[i].c] = max(dp[i+1][j+T[i].c], dp[i][j] + T[i].s);
        }
    }
    ll ans = *max_element(dp.back().begin(), dp.back().end());
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
