#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

int main() {
    int N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    S--;
    T--;
    X--;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<vector<ll>> even(N, vector<ll>(K+1, 0)), odd(N, vector<ll>(K+1, 0));
    even[S][0] = 1;
    for (int k = 0; k < K; k++) {
        for (int u = 0; u < N; u++) {
            for (int v : G[u]) {
                if (v != X) {
                    even[v][k+1] = (even[v][k+1] + even[u][k]) % 998244353;
                    odd[v][k+1] = (odd[v][k+1] + odd[u][k]) % 998244353;
                } else {
                    even[v][k+1] = (even[v][k+1] + odd[u][k]) % 998244353;
                    odd[v][k+1] = (odd[v][k+1] + even[u][k]) % 998244353;
                }
            }
        }
    }

    cout << even[T][K] << endl;
}
