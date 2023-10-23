#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
vector<vector<int>> G, H;

void dfs1(int v, vector<bool> &seen, vector<int> &I) {
    seen[v] = true;
    for (int w : G[v]) {
        if (!seen[w]) dfs1(w, seen, I);
    }
    I.push_back(v);
}

void dfs2(int v, vector<bool> &seen, vector<int> &J, int s) {
    seen[v] = true;
    J[s]++;
    for (int w : H[v]) {
        if (!seen[w]) dfs2(w, seen, J, s);
    }
}

int main() {
    cin >> N >> M;
    G.resize(N);
    H.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        H[v].push_back(u);
    }

    vector<bool> seen(N, false);
    vector<int> I;
    for (int i = 0; i < N; i++) {
        if (!seen[i]) dfs1(i, seen, I);
    }

    reverse(I.begin(), I.end());
    seen.assign(N, false);
    vector<int> J(N, 0);
    for (int i : I) {
        if (!seen[i]) dfs2(i, seen, J, i);
    }

    ll ans = 0;
    for (int j : J) {
        if (j >= 2) ans += (ll)j*(j-1)/2;
    }
    cout << ans << endl;
}
