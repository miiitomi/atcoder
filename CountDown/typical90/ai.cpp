#include <bits/stdc++.h>
using namespace std;

vector<int> p(21, 1);
int N;
vector<vector<int>> G;
vector<int> depth;
vector<vector<int>> par;
vector<int> W, X;

bool cmp(int &v, int &w) {
    return X[v] < X[w];
}

int lca(int s, int t) {
    if (s == t) return s;
    if (depth[s] > depth[t]) swap(s, t);
    if (depth[s] < depth[t]) {
        for (int k = 20; k >= 0 && (depth[s] != depth[t]); k--) {
            if (depth[t] - p[k] >= depth[s]) t = par[t][k];
        }
    }
    for (int k = 20; k >= 0; k--) {
        if (par[s][k] != par[t][k]) {
            s = par[s][k];
            t = par[t][k];
        }
    }
    if (s == t) return s;
    else return par[s][0];
}

void dfs(int s, vector<bool> &seen, vector<int> &V) {
    seen[s] = true;
    V.push_back(s);
    for (int w : G[s]) if (!seen[w]) dfs(w, seen, V);
}

int dist(int v, int w) {
    int l = lca(v, w);
    return depth[v] + depth[w] - 2*depth[l];
}

int main() {
    for (int k = 1; k <= 20; k++) p[k] = p[k-1] * 2;
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    par.assign(N, vector<int>(21, -1));
    depth.assign(N, -1);
    depth[0] = 0;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (depth[w] > -1) continue;
            par[w][0] = v;
            depth[w] = depth[v] + 1;
            Q.push(w);
        }
    }

    for (int k = 1; k <= 20; k++) for (int v = 0; v < N; v++) {
        if (par[v][k-1] != -1) par[v][k] = par[par[v][k-1]][k-1];
        else par[v][k] = -1;
    }

    vector<bool> seen(N, false);
    dfs(0, seen, W);
    X.resize(N);
    for (int i = 0; i < N; i++) X[W[i]] = i;

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;
        vector<int> V(K);
        for (int j = 0; j < K; j++) {
            cin >> V[j];
            V[j]--;
        }
        sort(V.begin(), V.end(), cmp);
        int ans = 0;
        for (int j = 0; j < (int)V.size()-1; j++) {
            ans += dist(V[j], V[j+1]);
        }
        ans += dist(V[(int)V.size()-1], V[0]);
        cout << ans / 2 << endl;
    }
}
