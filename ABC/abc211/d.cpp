#include <bits/stdc++.h>
using namespace std;
const int MOD = pow(10, 9) + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(0));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N, -1);
    dist[0] = 0;
    vector<int> cnt(N, 0);
    cnt[0] = 1;
    queue<int> que;
    que.push(0);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int nv : G[v]) {
            if (dist[nv] == -1) {
                dist[nv] = dist[v] + 1;
                cnt[nv] = cnt[v];
                que.push(nv);
            } else if (dist[nv] == dist[v] + 1) {
                cnt[nv] += cnt[v];
                cnt[nv] %= MOD;
            }
        }
    }

    cout << cnt[N-1] << endl;
}
