// https://atcoder.jp/contests/abc222/tasks/abc222_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void rec(int s, int par, vector<ll> &d, vector<vector<pair<int,ll>>> &G) {
    for (auto p : G[s]) {
        int v = p.first;
        ll c = p.second;
        if (v == par) continue;
        d[v] = d[s] + c;
        rec(v, s, d, G);
    }
}

int dfs(int s, vector<ll> &d, vector<vector<pair<int,ll>>> &G) {
    d.assign((int)G.size(), 1e+18);
    d[s] = 0;
    rec(s, -1, d, G);
    return (int)distance(d.begin(), max_element(d.begin(), d.end()));
}

int main() {
    int N;
    cin >> N;
    vector<vector<pair<int,ll>>> G(2*N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a += N-1;
        b += N-1;
        ll c;
        cin >> c;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }
    vector<ll> D(N);
    for (int i = 0; i < N; i++) {
        int j = N + i;
        ll d;
        cin >> d;
        G[j].push_back({i, d});
        G[i].push_back({j, d});
        D[i] = d;
    }

    int s = 0;
    vector<ll> d_t, d_u;
    int t = dfs(s, d_u, G);
    int u = dfs(t, d_t, G);
    dfs(u, d_u, G);

    for (int i = 0; i < N; i++) {
        cout << max(d_t[i], d_u[i]) - D[i] << endl;
    }
}
