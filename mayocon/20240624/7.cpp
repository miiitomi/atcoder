// https://atcoder.jp/contests/abc359/tasks/abc359_g
#include <bits/stdc++.h>
using namespace std;
const int B = 1000;
using ll = long long;

template< typename T > struct SparseTable {
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable(const vector< T > &v) {
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
vector<int> in, out, node, depth;

void euler_tour(int u, int p, int &num, int d) {
    in[u] = num;
    node.push_back(u);
    depth.push_back(d);
    for (int v : G[u]) {
        if (p == v) continue;
        num++;
        euler_tour(v, u, num, d+1);
        node.push_back(u);
        depth.push_back(d);
    }
    num++;
    out[u] = num;
}

void dfs(int u, int p, ll S, vector<bool> &is_in, vector<ll> &cnt, ll &ans) {
    if (is_in[u]) cnt[u]++;
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u, S, is_in, cnt, ans);
        cnt[u] += cnt[v];
    }
    ans += cnt[u] * (S - cnt[u]);
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
    in.resize(N); out.resize(N);

    int num = 0;
    euler_tour(0, -1, num, 0);
    SparseTable<int> st(depth);

    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        A[a].push_back(i);
    }

    ll ans = 0;

    for (int a = 0; a < N; a++) {
        if ((int)A[a].size() <= 1) continue;
        else if ((int)A[a].size() <= B) {
            for (int i = 0; i < (int)A[a].size(); i++) {
                for (int j = i+1; j < (int)A[a].size(); j++) {
                    int u = A[a][i], v = A[a][j];
                    int d = st.rmq(min(in[u], in[v]), max(out[u], out[v]));
                    ans += depth[in[u]]+depth[in[v]]-2*d;
                }
            }

        } else {
            vector<bool> is_in(N, false);
            for (int u : A[a]) is_in[u] = true;
            vector<ll> cnt(N, 0);
            dfs(0, -1, (ll)A[a].size(), is_in, cnt, ans);
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
