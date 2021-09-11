#include <bits/stdc++.h>
using namespace std;

int min_path(vector<vector<int>> &G, set<pair<int, int>> &S) {
    vector<pair<int, int>> d((int)G.size(), make_pair(-1, -1));
    d[0].first = 0;
    queue<int> Q;
    Q.push(0);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto nv : G[v]) {
            if (d[nv].first != -1) continue;
            d[nv].first = d[v].first + 1;
            d[nv].second = v;
            Q.push(nv);
        }
    }
    if (d[(int)G.size()-1].first == -1) return -1;

    int v = (int)G.size() - 1;
    while (v != 0) {
        S.insert(make_pair(d[v].second, v));
        v = d[v].second;
    }
    return d[(int)G.size()-1].first;
}

int bfs(vector<vector<int>> &G, int s, int t) {
    vector<int> d((int)G.size(), -1);
    d[0] = 0;
    queue<int> Q;
    Q.push(0);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int nv : G[v]) {
            if (d[nv] != -1 || (v == s && nv == t)) continue;
            d[nv] = d[v] + 1;
            Q.push(nv);
        }
    }
    return d[(int)G.size()-1];
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> s(M), t(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        s[i] = a;
        t[i] = b;
    }

    set<pair<int, int>> S;
    int min_distance = min_path(G, S);

    for (int i = 0; i < M; i++) {
        if (S.count(make_pair(s[i], t[i]))) cout << bfs(G, s[i], t[i]) << endl;
        else cout << min_distance << endl;
    }
}
