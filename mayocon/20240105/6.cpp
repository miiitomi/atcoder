// https://atcoder.jp/contests/abc294/tasks/abc294_g
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Data {
    int idx, depth;
    Data(int i, int d): idx(i), depth(d) {}
};

struct Edge {
    int idx, from, to;
    ll c;
    Edge(int i, int f, int t, ll c): idx(i), from(f), to(t), c(c) {}
};

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = Data(-1, 1e+9);  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        if (a.depth <= b.depth) return a;
        else return b;
    }

    // Update data[i] to a.
    void update(int i, T a) {
        i = n - 1 + i;
        data[i] = operation(data[i], a);  // TODO: Set update operation if needed (e.g. data[i] = a )
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i*2 + 1], data[i*2 + 2]);
        }
    }

    T _sub_query(int i, int j, int k, int l, int r) {
        if (r <= i || j <= l) return init_value;
        if (i <= l && r <= j) return data[k];
        T vl = _sub_query(i, j, 2*k + 1, l, (l + r)/2);
        T vr = _sub_query(i, j, 2*k + 2, (l + r)/2, r);
        return operation(vl, vr);
    }

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};

struct BIT {
    int n;
    vector<ll> data;

    BIT(int _n) {
        n = _n + 1;
        data.assign(n, 0);
    }

    void add(int i, ll x) {
        // Add x to a[i] (0-indexed).
        for (int idx = i + 1; idx < n; idx += (idx & -idx)) {
            data[idx] += x;
        }
    }

    ll sum(int i) {
        // compute sum of a[i] with i in [0, i)
        ll ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    ll sum(int a, int b) {
        // compute sum of a[i] with i in [a, b)
        return sum(b) - sum(a);
    }
};

void dfs(int u, Edge &par, vector<vector<Edge>> &G, vector<ll> &in, vector<ll> &out, vector<ll> &p, vector<ll> &m, BIT &bit, SegmentTree<Data> &st, int &cur, vector<ll> &depth) {
    if (par.idx != -1) {
        depth[u] = depth[par.from] + 1;
        p[par.idx] = cur;
        bit.add(cur, par.c);
    }
    st.update(cur, Data(u, depth[u]));
    in[u] = cur;

    for (Edge &e : G[u]) {
        int v = e.to;
        if (in[v] != -1) continue;
        cur++;
        dfs(v, e, G, in, out, p, m, bit, st, cur, depth);
    }

    cur++;
    out[u] = cur;
    if (par.idx != -1) {
        st.update(cur, Data(par.from, depth[par.from]));
        m[par.idx] = cur;
        bit.add(cur, -par.c);
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<Edge>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--;
        v--;
        G[u].push_back(Edge(i, u, v, c));
        G[v].push_back(Edge(i, v, u, c));
    }

    vector<ll> in(N, -1), out(N, -1), p(N-1, -1), m(N-1, -1), depth(N, 0);
    BIT bit(2*(N-1)+1);
    SegmentTree<Data> st(2*(N-1)+1);
    int cur = 0;
    Edge e(-1, -1, -1, -1);
    dfs(0, e, G, in, out, p, m, bit, st, cur, depth);

    int Q;
    cin >> Q;

    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int i, w;
            cin >> i >> w;
            i--;
            bit.add(p[i], -bit.sum(p[i], p[i]+1) + w);
            bit.add(m[i], -bit.sum(m[i], m[i]+1) - w);
        } else {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            int l = st.query(min(in[u], in[v]), max(out[u], out[v])).idx;
            ll du = bit.sum(in[0], in[u]+1);
            ll dv = bit.sum(in[0], in[v]+1);
            ll dl = bit.sum(in[0], in[l]+1);
            ll ans = du + dv - 2*dl;
            cout << ans << "\n";
        }
    }
}
