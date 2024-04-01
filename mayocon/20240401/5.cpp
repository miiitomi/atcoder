// https://atcoder.jp/contests/abc131/tasks/abc131_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    if (!(K <= (N-1)*(N-2)/2)) {
        cout << "-1\n";
        return;
    }
    vector<vector<bool>> G(N, vector<bool>(N, false));
    for (int u = 0; u < N; u++) {
        for (int v = u+1; v < N; v++) {
            G[u][v] = true;
        }
    }
    for (int u = 1; u < N; u++) {
        for (int v = u+1; v < N; v++) {
            if (K > 0) {
                G[u][v] = false;
                K--;
            }
        }
    }

    vector<pair<int,int>> ans;
    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            if(G[u][v]) ans.push_back(make_pair(u+1, v+1));
        }
    }

    cout << ans.size() << "\n";
    for (auto &p : ans) {
        cout << p.first << " " << p.second << "\n";
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
