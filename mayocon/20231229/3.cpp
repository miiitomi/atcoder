// https://atcoder.jp/contests/abc317/tasks/abc317_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N, vector<ll>(N, -1));
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        G[u][v] = c;
        G[v][u] = c;
    }

    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;

    ll ans = -1;
    do {
        ll tmp = 0;
        for (int i = 1; i < N; i++) {
            if (G[v[i-1]][v[i]] >= 0) {
                tmp += G[v[i-1]][v[i]];
            } else {
                break;
            }
        }
        ans = max(ans, tmp);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}
