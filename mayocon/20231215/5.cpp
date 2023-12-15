// https://atcoder.jp/contests/abc187/tasks/abc187_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(ll v, ll par, ll &N, vector<vector<pair<ll,ll>>> &G, vector<ll> &a, vector<ll> &b, vector<ll> &c, vector<vector<pair<ll,ll>>> &V) {
    for (auto p : G[v]) {
        if (p.first == par) continue;
        ll x = c[v];
        for (auto q : V[p.second]) {
            ll l = a[p.second], r = b[p.second];
            if (q.first == 2) swap(l, r);
            if (l == p.first) x += q.second;
            else x -= q.second;
        }
        c[p.first] = x;
        dfs(p.first, v, N, G, a, b, c, V);
    }
}

int main() {
    ll N;
    cin >> N;
    vector<vector<pair<ll,ll>>> G(N);
    vector<ll> a(N-1), b(N-1);
    for (ll i = 0; i < N-1; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        G[a[i]].push_back(make_pair(b[i], i));
        G[b[i]].push_back(make_pair(a[i], i));
    }
    vector<ll> d(N, -1);
    d[0] = 0;
    queue<ll> Q;
    Q.push(0);
    while (!Q.empty()) {
        ll v = Q.front();
        Q.pop();
        for (auto p : G[v]) {
            if (d[p.first] != -1) continue;
            d[p.first] = d[v] + 1;
            Q.push(p.first);
        }
    }

    vector<ll> c(N, 0);

    vector<vector<pair<ll,ll>>> V(N-1);
    ll K;
    cin >> K;
    while (K--) {
        ll t, e, x;
        cin >> t >> e >> x;
        e--;
        V[e].push_back(make_pair(t, x));

        ll l = a[e], r = b[e];
        if (t == 2) swap(l, r);
        if (d[l] < d[r]) c[0] += x;
    }

    dfs(0, -1, N, G, a, b, c, V);

    for (ll a : c) cout << a << "\n";
}
