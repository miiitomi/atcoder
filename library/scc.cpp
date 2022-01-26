// Storongly Connected Components 
// https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C

#include <iostream>
#include <vector>
using namespace std;

void dfs1(int v, vector<vector<int>> &G, vector<int> &I, vector<bool> &used) {
    if (used[v]) return;
    used[v] = true;

    for (int w : G[v]) {
        dfs1(w, G, I, used);
    }
    I.push_back(v);
}

void dfs2(int v, vector<vector<int>> &H, vector<int> &J, int &i) {
    if (J[v] != -1) return;
    J[v] = i;
    for (int w : H[v]) {
        dfs2(w, H, J, i);
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V), H(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        H[t].push_back(s);
    }

    vector<int> I;
    vector<bool> used(V, false);
    for (int i = 0; i < V; i++) {
        dfs1(i, G, I, used);
    }

    vector<int> J(V, -1);
    for (int i = 0; i < V; i++) {
        int v = I[V - 1 - i];
        dfs2(v, H, J, i);
    }

    int Q;
    cin >> Q;
    vector<int> u(Q), v(Q);
    for (int i = 0; i < Q; i++) {
        cin >> u[i] >> v[i];
    }

    for (int i = 0; i < Q; i++) {
        if (J[u[i]] == J[v[i]]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
