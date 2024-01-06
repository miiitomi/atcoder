// https://atcoder.jp/contests/abc202/tasks/abc202_e
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;
vector<int> in, out, depth, vertex;

void dfs(int u, int par, int &cur) {
    in[u] = cur;
    vertex[cur] = u;
    if (par != -1) depth[u] = depth[par] + 1;

    for (int v : G[u]) {
        if (v != par) {
            cur++;
            dfs(v, u, cur);
        }
    }

    cur++;
    out[u] = cur;
    if (par != -1) vertex[cur] = u;
    return;
}

int main() {
    cin >> N;
    G.resize(N);
    for (int i = 1; i <= N-1; i++) {
        int p;
        cin >> p;
        p--;
        G[p].push_back(i);
        G[i].push_back(p);
    }
    in.assign(N, -1);
    out.assign(N, -1);
    depth.assign(N, 0);
    vertex.assign(2*(N-1)+1, -1);

    int cur = 0;
    dfs(0, -1, cur);

    int Q;
    cin >> Q;
    vector<int> ans(Q, 0), U(Q, 0), D(Q, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ1, PQ2;
    for (int i = 0; i < Q; i++) {
        cin >> U[i] >> D[i];
        U[i]--;
        PQ1.push(make_pair(in[U[i]], i));
        PQ2.push(make_pair(out[U[i]], i));
    }

    vector<int> cnt(N, 0);

    for (int t = 0; t <= 2*(N-1)+1; t++) {
        while (!PQ1.empty() && PQ1.top().first == t) {
            int i = PQ1.top().second;
            PQ1.pop();
            int d = D[i];
            ans[i] -= cnt[d];
        }
        while (!PQ2.empty() && PQ2.top().first == t) {
            int i = PQ2.top().second;
            PQ2.pop();
            int d = D[i];
            ans[i] += cnt[d];
        }
        int v = vertex[t];
        if (in[v] == t) {
            cnt[depth[v]]++;
        }
    }

    for (int a : ans) cout << a << "\n";
}
