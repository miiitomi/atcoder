// https://atcoder.jp/contests/abc232/tasks/abc232_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N), H(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        H[a].push_back(b);
        H[b].push_back(a);
    }

    for (int u = 0; u < N; u++) sort(G[u].begin(), G[u].end());
    for (int u = 0; u < N; u++) sort(H[u].begin(), H[u].end());

    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;
    do {
        vector<vector<int>> I(N);
        for (int u = 0; u < N; u++) {
            for (int w : H[u]) {
                I[v[u]].push_back(v[w]);
            }
        }
        for (int u = 0; u < N; u++) sort(I[u].begin(), I[u].end());
        if (G == I) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << "No" << endl;
}
