#include <bits/stdc++.h>
using namespace std;

void solve() {
    int M, N;
    cin >> M >> N;

    if (N == 1) {
        cout << 0 << endl;
        for (int i = 0; i < M; i++) cout << 0 << endl;
        return;
    }

    if (M == 1) {
        cout << 2 << endl;
        for (int i = 0; i < N; i++) cout << i << " ";
        cout << endl;
        return;
    }

    vector<vector<int>> X(M, vector<int>(N, 0));
    int ans = 1;
    for (int i = 0; i < M; i++) {
        if ((i + 1) < N) {
            ans++;
            for (int j = 0; j < N; j++) {
                X[i][(i+1+j)%N] = j;
            }
        } else {
            for (int j = 0; j < N; j++) {
                X[i][(1+j)%N] = j;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << X[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
