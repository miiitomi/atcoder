// https://atcoder.jp/contests/abc286/tasks/abc286_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> A;
vector<string> S;

vector<pair<ll,ll>> dijkstra(int s) {
    vector<pair<ll,ll>> d(N, {INF, INF});
    d[s] = {0, -A[s]};
    priority_queue<pair<pair<ll,ll>,ll>, vector<pair<pair<ll,ll>,ll>>, greater<pair<pair<ll,ll>,ll>>> Q;
    Q.push(make_pair(d[s], s));
    while (!Q.empty()) {
        pair<ll,ll> p = Q.top().first;
        int u = Q.top().second;
        Q.pop();
        if (d[u] != p) continue;
        for (int v = 0; v < N; v++) {
            if (u == v || S[u][v] == 'N') continue;
            pair<ll,ll> q = {p.first+1, p.second-A[v]};
            if (q < d[v]) {
                d[v] = q;
                Q.push({d[v], v});
            }
        }
    }
    return d;
}

void solve() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    S.resize(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<vector<pair<ll,ll>>> d(N);
    for (int i = 0; i < N; i++) d[i] = dijkstra(i);

    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (d[u][v].first == INF) {
            cout << "Impossible\n";
        } else {
            cout << d[u][v].first << " " << -d[u][v].second << "\n";
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
