#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    int ans = 1e+9;

    for (int s = 0; s < (1 << N); s++) {
        vector<bool> cnt(M, false);
        int tmp = 0;
        for (int i = 0; i < N; i++) {
            if (!(s & (1 << i))) continue;
            tmp++;
            for (int j = 0; j < M; j++) {
                if (S[i][j] == 'o') cnt[j] = true;
            }
        }
        int c = 0;
        for (int j = 0; j < M; j++) c += cnt[j];
        if (c == M) {
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
