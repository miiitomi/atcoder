// https://atcoder.jp/contests/abc204/tasks/abc204_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int to;
    ll c;
    ll d;
    ll t;

    ll f(ll x) {
        return x + c + d/(x+1);
    }

    Edge(int _to, ll _c, ll _d) {
        to = _to;
        c = _c;
        d = _d;

        if (d <= 1) t = 0;
        else {
            double x = pow((double)d, 0.5) - 1.0;
            ll max_v = 1e+18;

            for (int k = -2; k <= 2; k++) {
                ll y = round(x) + k;
                if (y >= 0 && f(y) < max_v) {
                    t = y;
                    max_v = f(y);
                }
            }
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        G[a].push_back(Edge(b, c, d));
        G[b].push_back(Edge(a, c, d));
    }

    vector<ll> d(N, 1e+18);
    d[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    Q.push(make_pair(0, 0));

    while (!Q.empty()) {
        auto p = Q.top();
        int v = p.second;
        Q.pop();
        if (p.first != d[v]) continue;

        for (auto &e : G[v]) {
            ll time = e.f(max(d[v], e.t));
            if (time < d[e.to]) {
                d[e.to] = time;
                Q.push(make_pair(time, e.to));
            }
        }
    }

    if (d[N-1] == 1e18) cout << -1 << endl;
    else cout << d[N-1] << endl;
}
