#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> A[i][j];

    vector<bitset<2000>> B(N);
    vector<bitset<2000>> C(1000);
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) C[A[i][j]][i] = 1;
        for (int i = 0; i < N; i++) B[i] ^= C[A[i][j]];
        for (int i = 0; i < N; i++) C[A[i][j]][i] = 0;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) ans += B[i][j];
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
