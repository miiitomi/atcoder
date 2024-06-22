// https://atcoder.jp/contests/abc307/tasks/abc307_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<pair<ll,ll>>> G(N);
    for (int i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    ll K;
    cin >> K;
    vector<ll> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
    }

    ll D;
    cin >> D;
    vector<ll> X(D+1, 0);
    for (int i = 1; i <= D; i++) cin >> X[i];

    vector<ll> ans(N, -1);
    vector<vector<ll>> patients(D+1);
    for (ll a : A) {
        ans[a] = 0;
        patients[0].push_back(a);
    }

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Neighbors;
    vector<ll> dist(N, 1e+18);
    for (int d = 1; d <= D; d++) {

        for (int p : patients[d-1]) {
            for (auto e : G[p]) {
                if (ans[e.first] != -1) continue;
                Neighbors.push({e.second, e.first});
            }
        }

        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> PQ;
        while (!Neighbors.empty() && Neighbors.top().first <= X[d]) {
            ll u = Neighbors.top().second, tmpd = Neighbors.top().first;
            Neighbors.pop();
            if (ans[u] != -1) continue;
            ans[u] = d;
            dist[u] = tmpd;
            patients[d].push_back(u);
            PQ.push({dist[u], u});
        }

        while (!PQ.empty()) {
            ll u = PQ.top().second, tmpd = PQ.top().first;
            PQ.pop();
            if (tmpd != dist[u]) continue;
            for (auto e : G[u]) {
                if (dist[e.first] <= dist[u]+e.second || dist[u]+e.second > X[d]) continue;
                dist[e.first] = dist[u]+e.second;
                if (ans[e.first] == -1) {
                    ans[e.first] = d;
                    patients[d].push_back(e.first);
                }
                PQ.push({dist[e.first], e.first});
            }
        }
    }

    for (ll a : ans) cout << a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
