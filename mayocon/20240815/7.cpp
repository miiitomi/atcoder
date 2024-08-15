// https://atcoder.jp/contests/abc133/tasks/abc133_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct DisjointSparseTable {
    T identity_element = {INF, INF};    // TODO: Change identity_element if needed. e.g.) 0, 1, INF, etc.
    T f(T l, T r) {if (l.first <= r.first) return l; return r;}    // TODO: Change the function f if needed. e.g) min, max, etc.
    vector<vector<T>> st;
    vector<int> lookup;

    DisjointSparseTable(const vector<T> &v) {
        int b = 0;
        while ((1 << b) <= (int)v.size()) ++b;
        st.resize(b, vector<T>(v.size(), identity_element));
        for (int i = 0; i < (int)v.size(); i++) st[0][i] = v[i];
        for (int i = 1; i < b; i++) {
        int shift = 1 << i;
        for (int j = 0; j < (int)v.size(); j += (shift << 1)) {
                int t = min(j + shift, (int)v.size());
                st[i][t - 1] = v[t - 1];
                for (int k = t - 2; k >= j; k--) st[i][k] = f(v[k], st[i][k + 1]);
                if ((int)v.size() <= t) break;
                st[i][t] = v[t];
                int r = min(t + shift, (int)v.size());
                for (int k = t + 1; k < r; k++) st[i][k] = f(st[i][k - 1], v[k]);
            }
        }
        lookup.resize(1 << b);
        for (int i = 2; i < (int)lookup.size(); i++) {
            lookup[i] = lookup[i >> 1] + 1;
        }
    }

    T query(int l, int r) {
        // Return the answer in the interval [l, r).
        if (l >= --r) return st[0][l];
        int p = lookup[l ^ r];
        return f(st[p][l], st[p][r]);
    }
};

struct Edge {
    ll to;
    ll c;
    ll d;
    Edge(ll _t, ll _c, ll _d): to(_t), c(_c), d(_d) {};
};

ll N, Q;
vector<vector<Edge>> G;

vector<ll> in, out;
vector<pair<ll,ll>> dp;

void dfs1(ll u, ll p, ll d, ll &k) {
    in[u] = k;
    dp.push_back({d, u});
    for (auto &e : G[u]) {
        if (e.to == p) continue;
        k++;
        dfs1(e.to, u, d + e.d, k);
        k++;
        dp.push_back({d, u});
    }
    out[u] = k;
}

struct Query {
    ll c, d, ans;
    Query(ll _c, ll _d) {
        c = _c;
        d = _d;
        ans = 0;
    }
};
vector<Query> queries;
vector<vector<ll>> V, R;

void dfs2(ll u, ll p, vector<pair<ll,ll>> &cnt) {
    for (ll q : V[u]) {
        ll c = queries[q].c, d = queries[q].d;
        queries[q].ans += dp[in[u]].first - cnt[c].first + cnt[c].second * d;
    }
    for (ll q : R[u]) {
        ll c = queries[q].c, d = queries[q].d;
        queries[q].ans -= 2 * (dp[in[u]].first - cnt[c].first + cnt[c].second * d);
    }
    for (auto &e : G[u]) {
        if (e.to == p) continue;
        cnt[e.c] = {cnt[e.c].first + e.d, cnt[e.c].second + 1};
        dfs2(e.to, u, cnt);
        cnt[e.c] = {cnt[e.c].first - e.d, cnt[e.c].second - 1};
    }
}

void solve() {
    cin >> N >> Q;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--;
        G[a].push_back(Edge(b, c, d));
        G[b].push_back(Edge(a, c, d));
    }
    in.resize(N);
    out.resize(N);
    ll k = 0;
    dfs1(0, -1, 0, k);
    DisjointSparseTable<pair<ll,ll>> dst(dp);
    V.resize(N);
    R.resize(N);


    for (ll q = 0; q < Q; q++) {
        ll x, y, u, v;
        cin >> x >> y >> u >> v;
        x--; u--; v--;
        ll r = dst.query(min(in[u], in[v]), max(out[u], out[v])).second;
        queries.push_back(Query(x, y));
        V[u].push_back(q);
        V[v].push_back(q);
        R[r].push_back(q);
    }

    vector<pair<ll,ll>> cnt(N, {0, 0});
    dfs2(0, -1, cnt);
    for (ll q = 0; q < Q; q++) {
        cout << queries[q].ans << "\n";
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
