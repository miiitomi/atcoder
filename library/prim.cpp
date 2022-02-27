// https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back(make_pair(t, w));
        G[t].push_back(make_pair(s, w));
    }

    set<int> S;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    for (auto p : G[0]) {
        Q.push(make_pair(p.second, p.first));
    }
    S.insert(0);

    int ans = 0;
    while ((int)S.size() != N) {
        int v = Q.top().second;
        int w = Q.top().first;
        Q.pop();
        if (S.count(v)) continue;
        ans += w;
        S.insert(v);
        for (auto p : G[v]) {
            if (S.count(p.first)) continue;
            Q.push(make_pair(p.second, p.first));
        }
    }
    cout << ans << endl;
}
