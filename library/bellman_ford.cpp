// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e18;

int main() {
    int N, M, r;
    cin >> N >> M >> r;

    vector<vector<pair<ll, ll>>> G(N);
    for (int i = 0; i < M; i++) {
        ll s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(make_pair(t, d));
    }

    vector<ll> dist(N, INF);
    dist[r] = 0;

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

    if (exists_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int v = 0; v < N; v++) {
            if (dist[v] == INF) cout << "INF" << endl;
            else cout << dist[v] << endl;
        }
    }
}
