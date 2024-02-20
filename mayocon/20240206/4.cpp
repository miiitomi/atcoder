// https://atcoder.jp/contests/abc192/tasks/abc192_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;

struct Train {
    ll to, time, k;
    Train(ll _to, ll _time, ll _k): to(_to), time(_time), k(_k) {}
};

void solve() {
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    X--;
    Y--;
    vector<vector<Train>> G(N);
    for (int i = 0; i < M; i++) {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--;
        b--;
        G[a].push_back(Train(b, t, k));
        G[b].push_back(Train(a, t, k));
    }

    vector<ll> d(N, INF);
    d[X] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(make_pair(0, X));

    while (!Q.empty()) {
        ll u = Q.top().second, t = Q.top().first;
        Q.pop();
        if (t != d[u]) continue;
        for (Train &train : G[u]) {
            ll s = t;
            if (t % train.k != 0) s += train.k - (t % train.k);
            if (s + train.time < d[train.to]) {
                d[train.to] = s + train.time;
                Q.push(make_pair(d[train.to], train.to));
            }
        }
    }

    if (d[Y] == INF) cout << -1 << endl;
    else cout << d[Y] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
