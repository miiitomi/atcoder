// https://atcoder.jp/contests/abc204/tasks/abc204_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    ll to, c, d, t;

    ll f(ll x) {return x + c + d/(x+1);}

    void compute_t() {
        ll q = round(sqrt(d) - 1);
        ll tmp = 2e+18;
        for (ll x = q - 10; x <= q + 10; x++) {
            if (x < 0) continue;
            if (tmp > f(x)) {
                tmp = f(x);
                t = x;
            }
        }
        return;
    }

    Edge(ll _to, ll _c, ll _d): to(_to), c(_c), d(_d) {
        compute_t();
    }

    ll spend_time(ll _t) {
        if (_t >= t) return f(_t);
        else return f(t);
    }
};


void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<Edge>> G(N);
    for (int i = 0; i < M; i++) {
        ll u, v, c, d;
        cin >> u >> v >> c >> d;
        u--;
        v--;
        G[u].emplace_back(Edge(v, c, d));
        G[v].emplace_back(Edge(u, c, d));
    }

    vector<ll> d(N, 2e+18);
    d[0] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        pair<ll, ll> p = Q.top();
        Q.pop();
        ll u = p.second;
        ll t = p.first;
        if (t != d[u]) continue;
        for (Edge &e : G[u]) {
            ll v = e.to;
            if (d[v] > e.spend_time(t)) {
                d[v] = e.spend_time(t);
                Q.push(make_pair(d[v], v));
            }
        }
    }

    if (d[N-1] < 1e+18) cout << d[N-1] << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
