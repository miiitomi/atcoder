// https://atcoder.jp/contests/abc358/tasks/abc358_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i< N; i++) cin >> S[i];

    int ans = 1e+9;
    for (int s = 0; s < (1 << N); s++) {
        int cnt = 0;
        vector<bool> tmp(M, false);
        for (int i = 0; i < N; i++) {
            if (!(s & (1 << i))) continue;
            cnt++;
            for (int j = 0; j < M; j++) {
                if (S[i][j] == 'o') tmp[j] = true;
            }
        }
        bool is_ok = true;
        for (int j = 0; j < M; j++) if (!tmp[j]) is_ok = false;
        if (is_ok) {
            ans = min(ans, cnt);
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
