#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, L, R;
    cin >> N >> L >> R;
    R++;
    vector<vector<int>> G((int)(1 << N) + 1);
    for (int u = 0; u < (1 << N); u++) {
        for (int i = 0; u % (1 << i) == 0 && i <= N; i++) {
            int j = u / (1 << i);
            int v = (1 << i) * (j + 1);
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    vector<int> d((int)(1 << N)+1, -1);
    d[L] = L;
    queue<int> Q;
    Q.push(L);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (d[v] != -1) continue;
            d[v] = u;
            Q.push(v);
        }
    }
    vector<int> path;
    for (int x = R; true; x = d[x]) {
        path.push_back(x);
        if (x == L) break;
    }
    reverse(path.begin(), path.end());

    int ans = 0;

    for (int i = 0; i < (int)path.size()-1; i++) {
        int u = path[i], v = path[i+1];
        bool b = (u < v);
        if (!b) swap(u, v);
        int x = 0;
        while ((1 << x) < (v - u)) x++;
        cout << "? " << x << " " << u/(1 << x) << endl;
        int res;
        cin >> res;
        if (b) ans = (ans + res) % 100;
        else ans = (ans - res + 100) % 100;
    }

    cout << "! " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
