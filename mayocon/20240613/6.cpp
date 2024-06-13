// https://atcoder.jp/contests/abc267/tasks/abc267_f
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;

int most_far_point(int x) {
    vector<int> d(N, -1);
    d[x] = 0;
    queue<int> Q;
    Q.push(x);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (d[v] != -1) continue;
            d[v] = d[u] + 1;
            Q.push(v);
        }
    }
    auto iter = max_element(d.begin(), d.end());
    return (int)distance(d.begin(), iter);
}

vector<int> return_lr() {
    int l = most_far_point(0);
    int r = most_far_point(l);
    return vector<int>{l, r};
}

void dfs(int u, int p, vector<int> &path, vector<vector<pair<int,int>>> &Queries, vector<int> &ans) {
    for (auto &q: Queries[u]) {
        if (q.second <= (int)path.size()-1) {
            ans[q.first] = path[(int)path.size()-1-q.second];
        }
    }
    for (int v : G[u]) {
        if (p == v) continue;
        path.push_back(v);
        dfs(v, u, path, Queries, ans);
    }
    path.pop_back();
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> V = return_lr();
    int Q;
    cin >> Q;
    vector<int> ans(Q, -1);
    vector<vector<pair<int,int>>> Queries(N);
    for (int q = 0; q < Q; q++) {
        int u, k;
        cin >> u >> k;
        u--;
        Queries[u].push_back({q, k});
    }

    vector<int> path;
    for (int v : V) {
        path.push_back(v);
        dfs(v, -1, path, Queries, ans);
    }

    for (int a : ans) {
        if (a == -1) cout << a << "\n";
        else cout << a + 1 << "\n";
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
