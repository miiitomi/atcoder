// https://atcoder.jp/contests/abc142/tasks/abc142_f
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
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }
    vector<ll> ans(2*N, 0);
    for (int s = 0; s < N; s++) {
        vector<ll> d(N+1, INF), prev(N+1, -1);
        d[s] = 0;
        queue<ll> Q;
        Q.push(s);
        while (!Q.empty() && d[N] == INF) {
            ll u = Q.front();
            Q.pop();
            for (ll v : G[u]) {
                if (v == s) {
                    d[N] = d[u]+1;
                    prev[N] = u;
                    break;
                } else if (d[v] == INF) {
                    d[v] = d[u]+1;
                    prev[v] = u;
                    Q.push(v);
                }
            }
        }
        if (d[N] >= (ll)ans.size()) continue;
        ans.resize(0);
        ll u = N;
        while (u != s) {
            u = prev[u];
            ans.push_back(u);
        }
    }
    if ((ll)ans.size() > N) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (ll x : ans) {
        cout << x+1 << endl;
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
