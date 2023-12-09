// https://atcoder.jp/contests/abc237/tasks/abc237_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e+18;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        if (i != 0) H[i] -= H[0];
    }
    H[0] = 0;

    vector<vector<pair<int,ll>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(make_pair(v, max(0LL, H[v]-H[u])));
        G[v].push_back(make_pair(u, max(0LL, H[u]-H[v])));
    }

    vector<ll> c(N, INF);
    c[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    Q.push(make_pair(0, 0));

    while (!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        if (c[p.second] != p.first) continue;
        for (auto q : G[p.second]) {
            if (c[q.first] > c[p.second] + q.second) {
                c[q.first] = c[p.second] + q.second;
                Q.push(make_pair(c[q.first], q.first));
            }
        }
    }

    for (int i = 0; i < N; i++) c[i] += H[i];

    cout << -1 * (*min_element(c.begin(), c.end())) << endl;
}
