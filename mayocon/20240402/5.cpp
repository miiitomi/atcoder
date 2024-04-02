// https://atcoder.jp/contests/abc051/tasks/abc051_d
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e+9;

int N, M;
vector<vector<int>> G;
vector<vector<int>> d;

void compute_distance() {
    d = G;
    for (int u = 0; u < N; u++) {
        vector<vector<int>> d_new = d;
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                d_new[a][b] = min(d_new[a][b], d[a][u] + d[u][b]);
            }
        }
        swap(d, d_new);
    }
    return;
}

void solve() {
    cin >> N >> M;
    G.assign(N, vector<int>(N, INF));
    vector<int> x(M), y(M), z(M);
    for (int i = 0; i < N; i++) G[i][i] = 0;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a][b] = c;
        G[b][a] = c;
        x[i] = min(a, b);
        y[i] = max(a, b);
        z[i] = c;
    }
    compute_distance();

    vector<bool> ans(M, true);
    for (int s = 0; s < N; s++) {
        for (int t = 0; t < N; t++) {
            for (int j = 0; j < M; j++) {
                if (!ans[j]) continue;
                if ((d[s][t] == d[s][x[j]] + z[j] + d[y[j]][t]) || (d[s][t] == d[s][y[j]] + z[j] + d[x[j]][t])) {
                    ans[j] = false;
                }
            }
        }
    }
    int cnt = 0;
    for (int j = 0; j < M; j++) if (ans[j]) cnt++;
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
