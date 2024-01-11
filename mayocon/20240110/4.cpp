// https://atcoder.jp/contests/abc198/tasks/abc198_e
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> C, cnt, ans;
vector<vector<int>> G;

void dfs(int u, int par) {
    if (cnt[C[u]] == 0) ans.push_back(u);
    cnt[C[u]]++;
    for (int v : G[u]) {
        if (v != par) dfs(v, u);
    }
    cnt[C[u]]--;
}

int main() {
    cin >> N;
    C.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
    }
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cnt.assign(1e+5, 0);
    dfs(0, -1);
    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x+1 << "\n";
}
