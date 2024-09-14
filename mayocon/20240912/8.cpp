// https://atcoder.jp/contests/abc359/tasks/abc359_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
const int b = 500;

template<typename T> struct DisjointSparseTable {
    T identity_element = (T)1e+9;    // TODO: Change identity_element if needed. e.g.) 0, 1, INF, etc.
    T f(T l, T r) {return min(l, r);}    // TODO: Change the function f if needed. e.g) min, max, etc.
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

int N;
vector<vector<int>> G;
vector<int> A;
vector<vector<int>> B;

vector<int> in, out, depth;

void euler_tour(int u, int par, int d) {
    in[u] = depth.size();
    depth.push_back(d);
    for (int v : G[u]) {
        if (v == par) continue;
        euler_tour(v, u, d+1);
        depth.push_back(d);
    }
    out[u] = depth.size();
    depth.push_back(d);
}

void dfs(int u, int par, vector<ll> &dp, int c, ll &ans) {
    for (int v : G[u]) {
        if (v == par) continue;
        dfs(v, u, dp, c, ans);
        ans += dp[v] * ((ll)B[c].size() - dp[v]);
        dp[u] += dp[v];
    }
    if (A[u] == c) dp[u]++;
}

void solve() {
    cin >> N;
    G.resize(N);
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        B[A[i]].push_back(i);
    }
    in.resize(N);
    out.resize(N);
    euler_tour(0, -1, 0);
    DisjointSparseTable<int> dst(depth);

    ll ans = 0;
    vector<ll> dp;
    for (int c = 0; c < N; c++) {
        if ((int)B[c].size() <= b) {
            for (int i = 0; i < (int)B[c].size(); i++) {
                for (int j = i+1; j < (int)B[c].size(); j++) {
                    int u = B[c][i], v = B[c][j];
                    int l = dst.query(min(in[u],in[v]), max(out[u],out[v]));
                    ans += depth[in[u]] + depth[in[v]] - 2 * l;
                }
            }
        } else {
            dp.assign(N, 0);
            dfs(0, -1, dp, c, ans);
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
