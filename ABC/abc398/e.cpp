#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<vector<bool>> H(N, vector<bool>(N, false));
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        H[u][v] = true;
        H[v][u] = true;
    }
    vector<int> color(N, -1);
    color[0] = 0;
    queue<int> Q;
    Q.push(0);
    vector<vector<int>> X(2);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        X[color[u]].push_back(u);
        for (int v : G[u]) {
            if (color[v] != -1) continue;
            color[v] = 1 - color[u];
            Q.push(v);
        }
    }
    int r = 0;
    for (int u : X[0]) {
        for (int v : X[1]) {
            if (!H[u][v]) r++;
        }
    }

    bool turn = true;
    if (r % 2 == 1) cout << "First" << endl;
    else {
        cout << "Second" << endl;
        turn = false;
    }

    while (true) {
        if (turn) {
            for (int u : X[0]) {
                for (int v : X[1]) {
                    if (!H[u][v]) {
                        H[u][v] = true;
                        H[v][u] = true;
                        int a = min(u, v)+1, b = max(u, v) + 1;
                        cout << a << " " << b << endl;
                        turn = false;
                        break;
                    }
                }
                if (!turn) break;
            }
        } else {
            int i, j;
            cin >> i >> j;
            if (i == -1) return;
            i--; j--;
            H[i][j] = true;
            H[j][i] = true;
            turn = true;
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
