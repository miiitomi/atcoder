// https://atcoder.jp/contests/abc198/tasks/abc198_e
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> C;
vector<vector<int>> G;
map<int, int> M;
set<int> S;

void dfs(int v, int par) {
    if (!M.count(C[v]) | M[C[v]] == 0) S.insert(v+1);
    M[C[v]]++;

    for (int w : G[v]) {
        if (w == par) continue;
        dfs(w, v);
    }

    M[C[v]]--;
}

int main() {
    cin >> N;
    C.resize(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, -1);

    for (int v : S) cout << v << endl;
}
