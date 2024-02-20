#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void solve() {
    int N;
    cin >> N;
    vector<vector<pair<ll, ll>>> G(N);
    for (int i = 0; i < N-1; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        x--;
        G[i].push_back(make_pair(i+1, a));
        G[i].push_back(make_pair(x, b));
    }
    vector<ll> d(N, INF);
    d[0] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        ll dist = Q.top().first, u = Q.top().second;
        Q.pop();
        if (d[u] != dist) continue;
        for (pair<ll, ll> p : G[u]) {
            ll v = p.first;
            if (d[v] > d[u] + p.second) {
                d[v] = d[u] + p.second;
                Q.push(make_pair(d[v], v));
            }
        }
    }
    cout << d[N-1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
