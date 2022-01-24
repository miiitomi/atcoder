#include <bits/stdc++.h>
using namespace std;

const int INF = 1e+9;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    vector<int> d(N, INF);
    d[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> P;
    P.push(make_pair(0, 0));
    while (!P.empty()) {
        int v = P.top().second;
        int d_v = P.top().first;
        P.pop();
        if (d[v] != d_v) continue;
        for (auto p :  G[v]) {
            if (d[p.first] > d[v] + p.second) {
                d[p.first] = d[v] + p.second;
                P.push(make_pair(d[p.first], p.first));
            }
        }
    }

    vector<int> e(N, INF);
    e[N-1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, N-1));
    while (!Q.empty()) {
        int v = Q.top().second;
        int e_v = Q.top().first;
        Q.pop();
        if (e[v] != e_v) continue;
        for (auto p : G[v]) {
            if (e[p.first] > e[v] + p.second) {
                e[p.first] = e[v] + p.second;
                Q.push(make_pair(e[p.first], p.first));
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << d[i] + e[i] << endl;
    }
}
