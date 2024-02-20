// https://atcoder.jp/contests/abc231/tasks/abc231_d
#include <bits/stdc++.h>
using namespace std;

vector<bool> reached;

bool dfs(int u, int p, set<int> &S, vector<vector<int>> &G) {
    reached[u] = true;
    S.insert(u);
    for (int v : G[u]) {
        if (v == p) continue;
        if (S.count(v)) return false;
        else if (!reached[v]) {
            bool res = dfs(v, u, S, G);
            if (!res) return false;
        }
    }
    S.erase(u);
    return true;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> cnt(N, 0);
    vector<vector<int>> G(N);
    while (M--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cnt[a]++;
        cnt[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        if (cnt[i] > 2) {
            cout << "No" << endl;
            return;
        }
    }

    reached.assign(N, false);
    for (int u = 0; u < N; u++) {
        if (!reached[u]) {
            set<int> S;
            bool res = dfs(u, -1, S, G);
            if (!res) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
