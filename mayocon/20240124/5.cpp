// https://atcoder.jp/contests/abc245/tasks/abc245_f
#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<bool> &reached, vector<int> &path, set<int> &S, vector<bool> &is_loop, vector<vector<int>> &G) {
    reached[v] = true;
    path.push_back(v);
    S.insert(v);
    for (int w : G[v]) {
        if (reached[w]) {
            if (!S.count(w)) continue;
            else {
                is_loop[w] = true;
                for (auto iter = path.rbegin(); *iter != w; iter++) is_loop[w] = true;
            }
        } else {
            dfs(w, reached, path, S, is_loop, G);
        }
    }
    path.pop_back();
    S.erase(v);
    return;
}

void dfs2(int v, vector<bool> &reached, vector<vector<int>> &H) {
    reached[v] = true;
    for (int w : H[v]) {
        if (!reached[w]) dfs2(w, reached, H);
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N), H(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        H[v].push_back(u);
    }
    vector<bool> reached(N, false), is_loop(N, false);
    for (int v = 0; v < N; v++) {
        if (reached[v]) continue;
        vector<int> path;
        set<int> S;
        dfs(v, reached, path, S, is_loop, G);
    }

    reached.assign(N, false);
    for (int v = 0; v < N; v++) {
        if (is_loop[v]) dfs2(v, reached, H);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) cnt += reached[i];

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
