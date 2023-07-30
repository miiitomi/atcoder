#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rec(int v, vector<vector<int>> &G, vector<int> &d, int from) {
    d[v] = 1;
    for (int w : G[v]) {
        if (w == from) continue;
        d[v] += rec(w, G, d, v);
    }
    return d[v];
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> d(N, 0);
    rec(0, G, d, -1);

    ll ans = 0;
    for (int v = 0; v < N; v++) {
        if (G[v].size() <= 2) continue;
        vector<ll> c((int)G[v].size(), -1);
        for (int i = 0; i < (int)G[v].size(); i++) {
            if (d[G[v][i]] > d[v]) {
                c[i] = N - d[v];
            } else {
                c[i] = d[G[v][i]];
            }
        }

        vector<vector<ll>> dp((int)c.size(), vector<ll>(4, 0));
        dp[0][0] = 1;
        dp[0][1] = c[0];
        for (int i = 1; i < (int)c.size(); i++) {
            for (int k = 0; k < 4; k++) {
                dp[i][k] = dp[i-1][k];
                if (k > 0) dp[i][k] += dp[i-1][k-1] * c[i];
            }
        }
        ans += dp[(int)c.size()-1][3];
    }

    cout << ans << endl;
}
