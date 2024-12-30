#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u-1].push_back(v-1);
    }
    while (Q > 0) {
        int T = min(Q, 64);
        Q -= T;
        vector<int> A(T), B(T);
        vector<ull> dp(N, 0ULL);
        for (int t = 0; t < T; t++) {
            cin >> A[t] >> B[t];
            A[t]--; B[t]--;
            dp[A[t]] ^= (1ULL << t);
        }
        for (int u = 0; u < N; u++) {
            for (int v : G[u]) dp[v] |= dp[u];
        }
        for (int t = 0; t < T; t++) {
            if (dp[B[t]] & (1ULL << t)) cout << "Yes\n";
            else cout << "No\n";
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
