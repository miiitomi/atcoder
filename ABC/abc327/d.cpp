#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<vector<int>> &G, vector<int> &c) {
    for (int w : G[v]) {
        if (c[w] != 0) {
            if (c[w] == c[v]) return false;
        } else {
            c[w] = -c[v];
            bool ok = dfs(w, G, c);
            if (!ok) return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);

    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
        B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    vector<int> c(N, 0);
    for (int i = 0; i < N; i++) {
        if (c[i] == 0) {
            c[i] = 1;
            bool ok = dfs(i, G, c);
            if (!ok) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}
