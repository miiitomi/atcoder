// https://atcoder.jp/contests/abc198/tasks/abc198_e
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> C;
vector<vector<int>> G;
vector<bool> is_good;
map<int,int> mp;

void dfs(int v, int p) {
    if (!mp.count(C[v]) || mp[C[v]] == 0) {
        is_good[v] = true;
    }
    mp[C[v]]++;
    for (int w : G[v]) {
        if (w != p) {
            dfs(w, v);
        }
    }
    mp[C[v]]--;
}

void solve() {
    cin >> N;
    C.resize(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    G.resize(N);
    for (int k = 0; k < N-1; k++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    is_good.assign(N, false);
    dfs(0, -1);

    for (int k = 0; k < N; k++) {
        if (is_good[k]) {
            cout << k+1 << "\n";
        }
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
