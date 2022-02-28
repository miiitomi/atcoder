#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e18;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<ll, ll>>> G(N);
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(make_pair(b, c));
    }

    vector<ll> score(N, -INF);
    score[0] = 0;
    bool positive_cycle = false;

    for (int k = 0; k < N; k++) {
        bool update = false;
        bool last_vertex_update = false;

        for (int v = 0; v < N; v++) {
            for (pair<ll, ll> p : G[v]) {
                int w = p.first;
                ll c = p.second;
                if (score[w] < score[v] + c) {
                    score[w] = score[v] + c;
                    update = true;
                    if (w == N-1) last_vertex_update = true;
                }
            }
        }

        if (!update) break;
        if (k == N-1 && last_vertex_update) positive_cycle = true;
    }

    if (positive_cycle) cout << "inf" << endl;
    else cout << score[N-1] << endl;
}
