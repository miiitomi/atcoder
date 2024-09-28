#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+9;

int N;
vector<vector<int>> G;
vector<int> d, md;
vector<int> cnt;

void dfs(int u, int p, int k) {
    d[u] = k;
    md[u] = k;
    for (int v: G[u]) {
        if (v == p) continue;
        dfs(v, u, k+1);
        md[u] = max(md[u], md[v]);
    }
    if (k >= 1) {
        cnt[0]++;
        cnt[k]--;
    }
    cnt[md[u]+1]++;
}

void solve() {
    cin >> N;
    G.assign(N, vector<int>{});
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    d.assign(N, 0);
    md.assign(N, 0);
    cnt.assign(N+1, 0);
    dfs(0, -1, 0);
    int ma = *max_element(d.begin(), d.end());
    int ans = INF;
    for (int i = 0; i <= ma; i++) {
        ans = min(ans, cnt[i]);
        cnt[i+1] += cnt[i];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
