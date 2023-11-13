// https://atcoder.jp/contests/abc239/tasks/abc239_e
#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> X;
vector<vector<int>> G, S;

void rec(int i, int p) {
    vector<int> V;
    for (int j : G[i]) {
        if (j != p) {
            rec(j, i);
            for (int a : S[j]) V.push_back(a);
        }
    }
    V.push_back(X[i]);
    sort(V.begin(), V.end());
    for (int k = 0; k < min((int)V.size(), 20); k++) {
        S[i].push_back(V[(int)V.size() - 1 - k]);
    }
}

int main() {
    cin >> N >> Q;
    X.resize(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    G.resize(N);
    for (int q = 0; q < N-1; q++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    S.resize(N);
    rec(0, -1);

    for (int w = 0; w < Q; w++) {
        int v, k;
        cin >> v >> k;
        v--;
        k--;
        cout << S[v][k] << endl;
    }
}
