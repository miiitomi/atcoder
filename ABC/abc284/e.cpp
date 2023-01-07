#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void rec(int i, vector<vector<int>> &G, ll &K, vector<bool> &done) {
    for (int j : G[i]) {
        if (!done[j]) {
            K++;
            if (K >= 1e+6) return;
        }
    }

    for (int j : G[i]) {
        if (!done[j]) {
            done[j] = true;
            rec(j, G, K, done);
            done[j] = false;
        }
        if (K >= 1e+6) return;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> done(N, false);
    done[0] = true;
    ll K = 1;

    rec(0, G, K, done);

    if (K >= 1e+6) {
        cout << 1000000 << endl;
    } else {
        cout << K << endl;
    }
}
