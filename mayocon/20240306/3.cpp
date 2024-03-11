// https://atcoder.jp/contests/abc232/tasks/abc232_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> X(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        X[a][b] = true;
        X[b][a] = true;
    }
    vector<int> C(M), D(M);
    for (int i = 0; i < M; i++) {
        cin >> C[i] >> D[i];
        C[i]--;
        D[i]--;
    }

    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;

    do {
        vector<vector<bool>> Y(N, vector<bool>(N, false));
        for (int i = 0; i < M; i++) {
            int c = C[i], d = D[i];
            c = v[c];
            d = v[d];
            Y[c][d] = true;
            Y[d][c] = true;
        }
        if (X == Y) {
            cout << "Yes\n";
            return;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
