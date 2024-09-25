// https://atcoder.jp/contests/abc317/tasks/abc317_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N, vector<ll>(N, -1));
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a][b] = c;
        G[b][a] = c;
    }
    vector<int> v(N);
    iota(v.begin(), v.end(), 0);
    ll ans = -1;
    do {
        ll tmp = 0;
        for (int i = 0; i < N-1; i++) {
            if (G[v[i]][v[i+1]] == -1) break;
            tmp += G[v[i]][v[i+1]];
        }
        ans = max(ans, tmp);
    } while (next_permutation(v.begin(), v.end()));
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
