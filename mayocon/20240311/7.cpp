// https://atcoder.jp/contests/abc307/tasks/abc307_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int,ll>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    int K;
    cin >> K;
    vector<ll> day(N, 1e+18), d(N, 1e+18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q, NQ;
    for (int k = 0; k < K; k++) {
        int a;
        cin >> a;
        a--;
        NQ.push(make_pair(0, a));
    }

    int D;
    cin >> D;
    for (int j = 0; j <= D; j++) {
        ll x = 0;
        if (j > 0) cin >> x;
        while (!NQ.empty() && NQ.top().first <= x) {
            int u = NQ.top().second;
            ll dist = NQ.top().first;
            NQ.pop();
            if (dist > d[u] || day[u] <= j) continue;
            d[u] = dist;
            Q.push(make_pair(dist, u));
        }
        while (!Q.empty()) {
            ll dist = Q.top().first;
            int u = Q.top().second;
            Q.pop();
            if (d[u] < dist || day[u] <= j) continue;
            day[u] = j;
            for (auto &e : G[u]) {
                int v = e.first;
                ll tmp = e.second;
                if (d[v] <= d[u] + tmp || day[v] <= j) continue;
                if (d[u] + tmp <= x) {
                    d[v] = d[u] + tmp;
                    Q.push(make_pair(d[v], v));
                } else {
                    NQ.push(make_pair(tmp, v));
                }
            }
        }
    }

    for (ll a : day) {
        if (a == (ll)1e+18) cout << "-1\n";
        else cout << a << "\n";
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
