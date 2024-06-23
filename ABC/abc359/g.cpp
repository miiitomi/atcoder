#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int B = 1000;

template<typename T> struct SparseTable {
  vector<vector<T>> st;
  vector<int> lookup;

  SparseTable(const vector<T> &v) {
    int b = 0;
    while((1 << b) <= (int)v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < (int)v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < (int)lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return min(st[b][l], st[b][r - (1 << b)]);
  }
};

int N;
vector<vector<int>> G;
vector<int> discovery, finish, visiting, depth;

void dfs(int u, int p, int &idx, int d) {
    discovery[u] = idx;
    visiting.push_back(u);
    depth.push_back(d);
    for (int v : G[u]) {
        if (v == p) continue;
        idx++;
        dfs(v, u, idx, d+1);
        visiting.push_back(u);
        depth.push_back(d);
    }
    idx++;
    finish[u] = idx;
}

void dfs2(int u, int p, vector<ll> &cnt, ll &S, vector<bool> &is_in, ll &ans) {
    cnt[u] = 0;
    if (is_in[u]) cnt[u]++;

    for (int v : G[u]) {
        if (v == p) continue;
        dfs2(v, u, cnt, S, is_in, ans);
        cnt[u] += cnt[v];
    }

    if (p != -1) ans += cnt[u] * (S - cnt[u]);
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    discovery.resize(N);
    finish.resize(N);

    int idx = 0;
    dfs(0, -1, idx, 0);
    SparseTable<int> st(depth);

    vector<vector<int>> V(N);
    for (int u = 0; u < N; u++) {
        int x;
        cin >> x;
        x--;
        V[x].push_back(u);
    }

    ll ans = 0;
    for (int a = 0; a < N; a++) {
        if ((int)V[a].size() <= 1) continue;
        else if ((int)V[a].size() <= B) {
            for (int i = 0; i < (int)V[a].size(); i++) {
                for (int j = i+1; j < (int)V[a].size(); j++) {
                    int u = V[a][i], v = V[a][j];
                    int lca_depth = st.rmq(min(discovery[u], discovery[v]), max(finish[u],finish[v]));
                    ans += (depth[discovery[u]] - lca_depth) + (depth[discovery[v]] - lca_depth);
                }
            }
        } else {
            vector<ll> cnt(N, 0);
            vector<bool> is_in(N, false);
            for (int u : V[a]) is_in[u] = true;
            ll S = V[a].size();
            dfs2(0, -1, cnt, S, is_in, ans);
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
