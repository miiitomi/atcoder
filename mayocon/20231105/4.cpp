// https://atcoder.jp/contests/abc325/tasks/abc325_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, A, B, C;
vector<vector<ll>> D;

vector<ll> dijkstra(int s) {
    vector<ll> d(N, 1e+18);
    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(make_pair(0, s));

    while (!Q.empty()) {
        ll v = Q.top().second;
        ll dist = Q.top().first;
        Q.pop();
        if (d[v] < dist) continue;
        for (int w = 0; w < N; w++) {
            if (w == v) continue;
            ll nd = dist;
            if (s == 0) nd += D[v][w] * A;
            else nd += D[v][w] * B + C;
            if (d[w] > nd) {
                d[w] = nd;
                Q.push(make_pair(nd, w));
            }
        }
    }
    return d;
}

int main() {
    cin >> N >> A >> B >> C;
    D.assign(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> D[i][j];
    }

    vector<ll> d0 = dijkstra(0), d1 = dijkstra(N-1);
    ll ans = 1e+18;
    for (int i = 0; i < N; i++) ans = min(ans, d0[i] + d1[i]);

    cout << ans << endl;
}
