#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
vector<int> m;
vector<bool> p;
vector<ll> c;
vector<vector<int>> e;
vector<ll> dp;

ll rec(int i) {
    if (dp[i] != -1) return dp[i];

    if (p[i]) {
        dp[i] = 0;
        return dp[i];
    }

    if (m[i] == 0) {
        dp[i] = c[i];
        return dp[i];
    }

    ll ans = 0;
    for (int j : e[i]) {
        ans += rec(j);
    }
    dp[i] = min(ans, c[i]);
    return dp[i];
}

void solve() {
    cin >> N >> K;
    c.resize(N);
    for (int i = 0; i < N; i++) cin >> c[i];
    p.assign(N, false);
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        x--;
        p[x] = true;
    }
    m.resize(N);
    e.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> m[i];
        e[i].resize(m[i]);
        for (int j = 0; j < m[i]; j++) {
            cin >> e[i][j];
            e[i][j]--;
        }
    }
    dp.assign(N, -1);

    for (int i = 0; i < N; i++) {
        cout << rec(i) << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}
