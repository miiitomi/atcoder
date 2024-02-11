#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<pair<ll, ll>>> G(N);
    for (int i = 0; i < M; i++) {
        ll x, y, v;
        cin >> x >> y >> v;
        x--;
        y--;
        G[y].push_back(make_pair(x, v));
        G[x].push_back(make_pair(y, -v));
    }
    vector<ll> d(N, INF);
    for (int u = 0; u < N; u++) {
        if (d[u] != INF) continue;
        d[u] = 0;
        queue<int> Q;
        Q.push(u);
        vector<ll> tmp;
        while (!Q.empty()) {
            ll v = Q.front();
            Q.pop();
            tmp.push_back(d[v]);
            for (pair<ll, ll> e : G[v]) {
                if (d[e.first] == INF) {
                    d[e.first] = d[v] + e.second;
                    Q.push(e.first);
                } else {
                    if (d[e.first] != d[v] + e.second) {
                        cout << "No\n";
                        return;
                    }
                }
            }
        }
        sort(tmp.begin(), tmp.end());
        ll min_v = *min_element(tmp.begin(), tmp.end());
        ll max_v = *max_element(tmp.begin(), tmp.end());
        if (max_v - min_v > (ll)1e+9) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
