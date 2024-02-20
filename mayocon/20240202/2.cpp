// https://atcoder.jp/contests/abc166/tasks/abc166_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    vector<vector<int>> G(N);
    while (M--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        bool is_good = true;
        for (int j : G[i]) if (H[i] <= H[j]) is_good = false;
        if (is_good) cnt++;
    }
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
