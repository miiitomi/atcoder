#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> C(M), R(M, 0);
    vector<vector<int>> A(M);
    for (int i = 0; i < M; i++) {
        cin >> C[i];
        A[i].resize(C[i]);
        for (int j = 0; j < C[i]; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
        char c;
        cin >> c;
        if (c == 'o') R[i] = 1;
    }

    int ans = 0;
    for (int s = 0; s < (1 << N); s++) {
        bool is_ok = true;
        for (int i = 0; i < M; i++) {
            int cnt = 0;
            for (int a : A[i]) {
                if (s & (1 << a)) cnt++;
            }
            if ((cnt >= K && R[i] == 0) || (cnt < K && R[i] == 1)) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) ans++;
    }

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
