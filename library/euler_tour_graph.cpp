struct EulerTour {
    template<typename T> struct DisjointSparseTable {
        T identity_element = make_pair((int)1e+9, (int)1e+9);    // TODO: Change identity_element if needed. e.g.) 0, 1, INF, etc.
        T f(T l, T r) {return min(l, r);}    // TODO: Change the function f if needed. e.g) min, max, etc.
        vector<vector<T>> st;
        vector<int> lookup;

        DisjointSparseTable() {}

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
    int n, root;
    DisjointSparseTable<pair<int,int>> dsu;
    vector<int> in, out;
    vector<pair<int,int>> depth;

    void dfs(int u, int p, int d, vector<vector<int>> &G) {
        in[u] = depth.size();
        depth.push_back({d, u});
        for (int v : G[u]) {
            if (v == p) continue;
            dfs(v, u, d+1, G);
            depth.push_back({d, u});
        }
        out[u] = depth.size();
        depth.push_back({d, u});
    }

    EulerTour(vector<vector<int>> &G, int r) {
        n = G.size();
        root = r;
        in.resize(n);
        out.resize(n);
        dfs(root, -1, 0, G);
        dsu = DisjointSparseTable<pair<int,int>>(depth);
    }

    EulerTour(vector<vector<int>> &G) {
        EulerTour(G, 0);
    }

    int lca(int u, int v) {
        return dsu.query(min(in[u],in[v]), max(out[u],out[v])).second;
    }

    int lca_depth(int u, int v) {
        return dsu.query(min(in[u],in[v]), max(out[u],out[v])).first;
    }

    int return_depth(int u) {
        return depth[in[u]].first;
    }

    int return_distance(int s, int t) {
        return return_depth(s) + return_depth(t) - 2*lca_depth(s, t);
    }
};