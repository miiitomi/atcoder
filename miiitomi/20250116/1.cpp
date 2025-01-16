// https://atcoder.jp/contests/abc276/tasks/abc276_b
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
    vector<vector<ll>> G(N);
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        cout << G[i].size() << " ";
        sort(G[i].begin(), G[i].end());
        for (ll a : G[i]) cout << a+1 << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
