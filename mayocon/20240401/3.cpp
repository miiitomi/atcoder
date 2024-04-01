// https://atcoder.jp/contests/abc285/tasks/abc285_d
#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, set<int> &path, vector<bool> &done, vector<int> &G) {
    done[u] = true;
    path.insert(u);
    if (G[u] == -1) return true;
    else if (path.count(G[u])) return false;
    else if (done[G[u]]) return true;
    else return dfs(G[u], path, done, G);
}

void solve() {
    int N;
    cin >> N;
    vector<string> S(N), T(N), v;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
        v.push_back(S[i]);
        v.push_back(T[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<int> G(v.size(), -1);
    for (int i = 0; i < N; i++) {
        int s = distance(v.begin(), lower_bound(v.begin(), v.end(), S[i]));
        int t = distance(v.begin(), lower_bound(v.begin(), v.end(), T[i]));
        G[s] = t;
    }

    vector<bool> done(v.size(), false);
    for (int u = 0; u < (int)v.size(); u++) {
        if (done[u]) continue;
        set<int> path;
        if (!dfs(u, path, done, G)) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
