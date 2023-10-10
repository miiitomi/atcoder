// https://atcoder.jp/contests/abc224/tasks/abc224_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int M;
    cin >> M;
    vector<vector<ll>> G(9);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> q(9, -1);
    for (int i = 0; i < 8; i++) {
        int s;
        cin >> s;
        s--;
        q[s] = i;
    }

    vector<int> s(9);
    for (int i = 0; i < 8; i++) s[i] = i;
    s[8] = -1;

    map<vector<int>, ll> mp;
    mp[s] = 0;
    queue<vector<int>> Q;
    Q.push(s);

    while (!Q.empty()) {
        auto v = Q.front();
        Q.pop();

        int e = distance(v.begin(), find(v.begin(), v.end(), -1));
        for (int w : G[e]) {
            vector<int> nv = v;
            int i = v[w];
            nv[e] = i;
            nv[w] = -1;

            if (mp.count(nv)) continue;

            mp[nv] = mp[v] + 1;
            Q.push(nv);
        }
    }

    if (mp.count(q)) cout << mp[q] << endl;
    else cout << -1 << endl;
}
