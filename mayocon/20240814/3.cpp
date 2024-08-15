// https://atcoder.jp/contests/abc211/tasks/abc211_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
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
    vector<ll> d(N, INF);
    vector<mint> cnt(N, 0);
    d[0] = 0;
    cnt[0] = 1;
    queue<ll> Q;
    Q.push(0);
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (ll v : G[u]) {
            if (d[v] >= d[u] + 1) {
                cnt[v] += cnt[u];
                if (d[v] > d[u]+1) {
                    d[v] = d[u]+1;
                    Q.push(v);
                }
            }
        }
    }
    cout << cnt.back().val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
