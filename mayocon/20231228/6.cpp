// https://atcoder.jp/contests/abc061/tasks/abc061_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e+18;

void dfs(int u, vector<bool> &reached, vector<vector<pair<ll, ll>>> &H) {
    for (auto &e : H[u]) {
        if (reached[e.first]) continue;
        reached[e.first] = true;
        dfs(e.first, reached, H);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<ll, ll>>> G(N), H(N);
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        H[b].push_back(make_pair(a, c));
    }

    vector<bool> reached(N, false);
    reached[N-1] = true;
    dfs(N-1, reached, H);

    for (int i = 0; i < N; i++) {
        if (!reached[i]) continue;
        for (auto &e : H[i]) {
            if (!reached[e.first]) continue;
            G[e.first].push_back(make_pair(i, -e.second));
        }
    }

    vector<ll> dist(N, INF);
    dist[0] = 0;

    bool exists_negative_cycle = false;
    for (int i = 0; i < N; i++) {
        bool update = false;

        for (int v = 0; v < N; v++) {
            if (dist[v] == INF) continue;

            for (auto p : G[v]) {
                if (dist[v] + p.second < dist[p.first]) {
                    update = true;
                    dist[p.first] = dist[v] + p.second;
                }
            }
        }

        if (!update) break;

        if (i == N-1 && update) exists_negative_cycle = true;
    }

    if (exists_negative_cycle) cout << "inf" << endl;
    else cout << -dist[N-1] << endl;

}
