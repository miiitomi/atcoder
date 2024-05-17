// https://atcoder.jp/contests/abc340/tasks/abc340_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<vector<pair<int,ll>>> G(N);
    for (int i = 0; i < N-1; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        x--;
        G[i].push_back(make_pair(i+1, a));
        G[i].push_back(make_pair(x, b));
    }

    vector<ll> d(N, (ll)1e+18);
    d[0] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> Q;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        int u = Q.top().second;
        ll dist = Q.top().first;
        Q.pop();
        if (d[u] != dist) continue;
        for (auto e : G[u]) {
            int v = e.first;
            ll w = e.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                Q.push(make_pair(d[v], v));
            }
        }
    }

    cout << d.back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
