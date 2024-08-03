// https://atcoder.jp/contests/abc218/tasks/abc218_f
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
    vector<vector<pair<ll,ll>>> G(N);
    for (int i = 0; i < M; i++) {
        ll s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back({t, i});
    }
    vector<ll> d(N, -1), from_idx(N, -1), from_ver(N, -1);
    d[0] = 0;
    queue<ll> Q;
    Q.push(0);
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (auto &e : G[u]) {
            ll v = e.first, idx = e.second;
            if (d[v] != -1) continue;
            d[v] = d[u] + 1;
            from_idx[v] = idx;
            from_ver[v] = u;
            Q.push(v);
        }
    }

    if (d[N-1] == -1) {
        for (int i = 0; i < M; i++) {
            cout << -1 << "\n";
        }
        return;
    }

    vector<bool> used(M, false);
    ll u = N-1;
    while (u != 0) {
        used[from_idx[u]] = true;
        u = from_ver[u];
    }

    for (ll i = 0; i < M; i++) {
        if (!used[i]) {
            cout << d[N-1] << "\n";
        } else {
            vector<ll> new_d(N, -1);
            new_d[0] = 0;
            Q.push(0);
            while (!Q.empty()) {
                ll u = Q.front();
                Q.pop();
                for (auto &e : G[u]) {
                    ll v = e.first, idx = e.second;
                    if (new_d[v] != -1 || idx == i) continue;
                    new_d[v] = new_d[u]+1;
                    Q.push(v);
                }
            }
            cout << new_d[N-1] << "\n";
        }
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
