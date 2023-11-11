#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, K;
vector<vector<ll>> G;
ll ans;

void rec(vector<int> &v, int i, ll &tmp) {
    int u = v[i];
    if (i == 0) {
        tmp = 0;
        rec(v, 1, tmp);
    } else if (i == N-1) {
        for (int j = 0; j < i; j++) {
            int w = v[j];
            if (G[u][w] > 0) {
                ans = min(ans, (tmp + G[u][w]) % K);
            }
        }
    } else {
        for (int j = 0; j < i; j++) {
            int w = v[j];
            if (G[u][w] < 0) continue;
            tmp += G[u][w];
            rec(v, i + 1, tmp);
            tmp -= G[u][w];
        }
    }
}

int main() {
    cin >> N >> M >> K;
    G.assign(N, vector<ll>(N, -1));
    for (int i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u][v] = w;
        G[v][u] = w;
    }

    vector<int> v;
    for (int i = 0; i < N; i++) v.push_back(i);

    ans = K;

    do {
        ll tmp = 0;
        rec(v, 0, tmp);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}
