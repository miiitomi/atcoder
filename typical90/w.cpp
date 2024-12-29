#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int H, W;
vector<vector<int>> v;

void dfs(int s, int n, int w) {
    if (n == W+1) {
        v[w].push_back(s);
        return;
    }
    dfs(s << 1, n+1, w);
    if ((w+n)%W != 0 && s&1) return;
    else if (s & (1 << (W-1))) return;
    else if ((w+n)%W != 0 && s&(1<<W)) return;
    else if ((w+n)%W != W-1 && s&(1<<(W-2))) return;
    dfs((s << 1) + 1, n+1, w);
}

void solve() {
    cin >> H >> W;
    vector<bool> C(H*W, false);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == '#') C[i*W+j] = true;
        }
    }
    v.resize(W);
    for (int w = 0; w < W; w++) {
        dfs(0, 0, w);
        sort(v[w].begin(), v[w].end());
    }
    vector<vector<vector<int>>> T(W);
    for (int w = 0; w < W; w++) {
        T[w].resize(v[w].size());
        for (int i = 0; i < (int)v[w].size(); i++) {
            int s = v[w][i];
            int t = (s << 1) & ((1 << (W+1))-1);
            auto iter = lower_bound(v[(w+1)%W].begin(), v[(w+1)%W].end(), t);
            T[w][i].push_back(distance(v[(w+1)%W].begin(), iter));
            if (w < W-1 && s&(1 << W)) continue;
            iter++;
            t += 1;
            if (iter != v[(w+1)%W].end() && *iter == t) T[w][i].push_back(distance(v[(w+1)%W].begin(), iter));
        }
    }
    vector<mint> dp(2, 1);
    if (C[0]) dp[1] = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (h == H-1 && w == W-1) continue;
            vector<mint> ndp(v[(w+1)%W].size(), 0);
            for (int i = 0; i < (int)dp.size(); i++) {
                for (int j : T[w][i]) {
                    if (v[(w+1)%W][j]&1 && C[h*W+w+1]) continue;
                    ndp[j] += dp[i];
                }
            }
            swap(dp, ndp);
        }
    }
    mint ans = 0;
    for (auto x : dp) ans += x;
    cout << ans.val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
