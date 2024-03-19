// https://atcoder.jp/contests/abc220/tasks/abc220_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<vector<int>> G;
vector<ll> depth, par, cnt, dp, ans;

void dfs(int i, int p) {
    for (int c : G[i]) {
        if (c == p) continue;
        depth[c] = depth[i] + 1;
        par[c] = i;
        dfs(c, i);
        cnt[i] += cnt[c];
        dp[i] += cnt[c] + dp[c];
    }
    cnt[i]++;
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    depth.assign(N, 0);
    par.assign(N, -1);
    cnt.assign(N, 0);
    dp.assign(N, 0);

    dfs(0, -1);

    ans.assign(N, 0);
    ans[0] = dp[0];

    vector<int> v;
    for (int i = 1; i < N; i++) v.push_back(i);
    sort(v.begin(), v.end(), [](const int i, const int j) {return depth[i] < depth[j];});

    for (int i : v) {
        int p = par[i];
        ans[i] = (ans[p] - (dp[i] + cnt[i])) + (N - cnt[i]) + dp[i];
    }

    for (ll u : ans) cout << u << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
