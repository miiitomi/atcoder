#include <bits/stdc++.h>
using namespace std;

int N;
vector<set<int>> G;
vector<int> ans;
vector<int> dp;

int tree_dp(int v, int p, int &K) {
    K++;
    dp[v] = 1;
    for (int w : G[v]) {
        if (w == p) continue;
        dp[v] += tree_dp(w, v, K);
    }
    return dp[v];
}

void rec(int v, int p) {
    int K = 0;
    tree_dp(v, p, K);

    if (K == 1) {
        ans[v] = p;
        return;
    }

    int q = p;
    while (true) {
        int max_v = -1;
        int max_idx = -1;
        for (int w : G[v]) {
            if (w == q) continue;
            if (max_v < dp[w]) {
                max_v = dp[w];
                max_idx = w;
            }
        }
        if (max_v <= K/2) break;
        q = v;
        v = max_idx;
    }
    ans[v] = p;

    for (int w : G[v]) {
        G[w].erase(v);
        rec(w, v);
    }
}

int main() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].insert(b);
        G[b].insert(a);
    }

    ans.assign(N, -1);
    dp.assign(N, -1);

    rec(0, -1);

    for (int v : ans) {
        if (v == -1) cout << v << " ";
        else cout << v+1 << " ";
    }
    cout << endl;
}
