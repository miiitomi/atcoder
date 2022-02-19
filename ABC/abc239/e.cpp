#include <bits/stdc++.h>
using namespace std;

struct Node {
    int bango = -1;
    int seisu = -1;
    int omomi = -1;
    bool done = false;
    vector<int> ko;
    vector<int> dp;

    Node(int bango_, int seisu_) {
        bango = bango_;
        seisu = seisu_;
    }
};

vector<Node> V;

int bfs(int v, vector<vector<int>> &G) {
    int nodes = 1;
    V[v].done = true;

    for (int w : G[v]) {
        if (V[w].done) continue;
        V[v].ko.push_back(w);
        nodes += bfs(w, G);
    }
    V[v].omomi = nodes;
    return nodes;
}

bool cmp(const int &a, const int &b) {
    if (V[a].omomi < V[b].omomi) return true;
    else return false;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        V.push_back(Node(i, x));
    }

    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> v(Q), k(Q);
    for (int i = 0 ; i < Q; i++) {
        cin >> v[i] >> k[i];
        v[i]--;
        k[i]--;
    }

    bfs(0, G);

    vector<int> W;
    for (int i = 0; i < N; i++) W.push_back(i);
    sort(W.begin(), W.end(), cmp);

    for (int w : W) {
        for (int k : V[w].ko) {
            for (int a : V[k].dp) {
                V[w].dp.push_back(a);
            }
        }
        V[w].dp.push_back(V[w].seisu);
        sort(V[w].dp.begin(), V[w].dp.end());
        reverse(V[w].dp.begin(), V[w].dp.end());

        if (V[w].dp.size() > 20) {
            V[w].dp.resize(20);
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << V[v[i]].dp[k[i]] << endl;
    }
}
