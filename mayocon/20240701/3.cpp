// https://atcoder.jp/contests/abc232/tasks/abc232_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    vector<int> C(M), D(M);
    for (int i = 0; i < M; i++) {
        cin >> C[i] >> D[i];
        C[i]--; D[i]--;
    }
    vector<int> v;
    for (int i = 0; i < N; i++) v.push_back(i);

    do {
        vector<vector<int>> H(N, vector<int>(N, 0));
        for (int i = 0; i < M; i++) {
            int c = v[C[i]], d = v[D[i]];
            H[c][d] = 1;
            H[d][c] = 1;
        }
        if (G == H) {
            cout << "Yes\n";
            return;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << "No\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
