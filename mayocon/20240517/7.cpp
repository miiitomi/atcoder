// https://atcoder.jp/contests/abc221/tasks/abc221_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<vector<int>> G;

int dfs(int u, int par, vector<int> &dist, int target) {
    int ans = 0;
    if (target == dist[u]) ans++;
    for (int v : G[u]) {
        if (v != par) {
            dist[v] = dist[u]+1;
            ans += dfs(v, u, dist, target);
        }
    }
    return ans;
}

void solve() {
    int N;
    cin >> N;
    G.resize(N);
    for (int q = 0; q < N-1; q++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<int> dist(N, 0);
    dfs(0, -1, dist, -1);
    int S = distance(dist.begin(), max_element(dist.begin(), dist.end()));
    dist.assign(N, 0);
    dfs(S, -1, dist, -1);
    int D = *max_element(dist.begin(), dist.end());
    int T = distance(dist.begin(), max_element(dist.begin(), dist.end()));

    vector<int> X(D+1, T);
    for (int i = D; i >= 1; i--) {
        int u = X[i];
        for (int v : G[u]) {
            if (dist[v] == dist[u]-1) {
                X[i-1] = v;
                break;
            }
        }
    }

    mint ans;
    if (D % 2 == 0) {
        int u = X[D/2];
        dist.assign(N, 0);
        ans = 1;
        mint sum = 1;
        for (int v : G[u]) {
            mint tmp = dfs(v, u, dist, D/2 - 1);
            sum += tmp;
            ans *= tmp+1;
        }
        ans -= sum;
    } else {
        int a = X[(D-1)/2], b = X[(D+1)/2];
        dist.assign(N, 0);
        mint ma = dfs(a, b, dist, (D-1)/2);
        mint mb = dfs(b, a, dist, (D-1)/2);
        ans = ma*mb;
    }

    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
