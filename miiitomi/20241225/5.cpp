// https://atcoder.jp/contests/abc247/tasks/abc247_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N = 2e+5;
    vector<mint> F(N+1, 0), G(N+1, 0);
    F[1] = 2;
    F[2] = 3;
    for (int x = 3; x <= N; x++) F[x] = F[x-1] + F[x-2];
    G[1] = 1;
    G[2] = 3;
    G[3] = 4;
    for (int x = 4; x <= N; x++) G[x] = F[x-1] + F[x-3];
    cin >> N;
    dsu U(N);
    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) {
        cin >> Q[i];
        U.merge(P[i]-1, Q[i]-1);
    }
    mint ans = 1;
    for (int u = 0; u < N; u++) {
        if (u != U.leader(u)) continue;
        ans *= G[U.size(u)];
    }
    cout << ans.val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
