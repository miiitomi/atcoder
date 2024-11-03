// https://atcoder.jp/contests/abc131/tasks/abc131_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M = 1e+5;
    cin >> N;
    dsu uf(2*M);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        uf.merge(x, M+y);
    }
    vector<vector<ll>> cnt(2*M, vector<ll>(2, 0));
    for (int u = 0; u < 2*M; u++) {
        int r = uf.leader(u);
        if (u < M) cnt[r][0]++;
        else cnt[r][1]++;
    }
    ll ans = -N;
    for (int u = 0; u < 2*M; u++) {
        ans += cnt[u][0]*cnt[u][1];
    }
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
