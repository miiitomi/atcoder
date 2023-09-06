// https://atcoder.jp/contests/abc239/tasks/abc239_e
#include <bits/stdc++.h>
using namespace std;

vector<int> X;
vector<vector<int>> G;
vector<vector<int>> V;

void rec(int v, int par) {
    V[v].reserve(max(1+20*((int)G[v].size()-1), 1));
    for (int c : G[v]) {
        if (c == par) continue;
        rec(c, v);
        for (int i = 0; i < min(20, (int)V[c].size()); i++) {
            V[v].push_back(V[c][i]);
        }
    }
    V[v].push_back(X[v]);
    sort(V[v].begin(), V[v].end());
    reverse(V[v].begin(), V[v].end());
}


int main() {
    int N, Q;
    cin >> N >> Q;
    X.resize(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    V.resize(N);
    rec(0, -1);

    for (int q = 0; q < Q; q++) {
        int v, k;
        cin >> v >> k;
        v--;
        k--;
        cout << V[v][k] << endl;
    }
}
