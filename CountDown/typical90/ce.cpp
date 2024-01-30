#include <bits/stdc++.h>
using namespace std;

void solve() {
    int B = 1000, N, M, Q;
    cin >> N >> M;
    vector<vector<int>> G(N), H(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        for (int j : G[i]) {
            if ((int)G[j].size() >= B) H[i].push_back(j);
        }
    }

    vector<int> C(N, 1), T(N, 0);
    vector<pair<int,int>> V(N, make_pair(0, 1));

    cin >> Q;
    for (int t = 1; t <= Q; t++) {
        int x, y;
        cin >> x >> y;
        x--;
        if ((int)G[x].size() < B) {
            for (int z : G[x]) {
                if (T[x] < V[z].first) {
                    C[x] = V[z].second;
                    T[x] = V[z].first;
                }
            }
        }
        cout << C[x] << "\n";

        V[x].first = t;
        V[x].second = y;
        C[x] = y;
        T[x] = t;
        for (int z : H[x]) {
            C[z] = C[x];
            T[z] = T[x];
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
