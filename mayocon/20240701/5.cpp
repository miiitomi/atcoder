// https://atcoder.jp/contests/abc310/tasks/abc310_d
#include <bits/stdc++.h>
using namespace std;

int N, T, M;
vector<vector<int>> G;
int ans = 0;

void dfs(int i, vector<int> &v) {
    if (i == N) {
        for (int j = 0; j < T; j++) {
            if (v[j] == 0) return;
        }
        ans++;
        return;
    }

    int cnt = 0;
    for (int j = 0; j < T; j++) if (v[j] == 0) cnt++;
    if (N-i < cnt) return;

    for (int j = 0; j < T; j++) {
        bool is_ok = true;
        for (int &a : G[i]) {
            if (v[j] & (1 << a)) {
                is_ok = false;
                break;
            }
        }
        if (!is_ok) continue;
        v[j] += (1 << i);
        dfs(i+1, v);
        v[j] -= (1 << i);
        if (v[j] == 0) return;
    }
}

void solve() {
    cin >> N >> T >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[b].push_back(a);
    }
    vector<int> v(T, 0);
    ans = 0;
    dfs(0, v);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
