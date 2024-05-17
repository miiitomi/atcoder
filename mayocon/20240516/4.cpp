// https://atcoder.jp/contests/abc128/tasks/abc128_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> k(M);
    vector<vector<int>> s(M);
    for (int i = 0; i < M; i++) {
        cin >> k[i];
        s[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    vector<int> p(M);
    for (int i = 0; i < M; i++) cin >> p[i];

    int ans = 0;
    for (int st = 0; st < (1 << N); st++) {
        bool is_ok = true;
        for (int i = 0; i < M; i++) {
            int cnt = 0;
            for (int j : s[i]) {
                cnt += (bool)(st & (1 << j));
            }
            if ((cnt % 2) != p[i]) {
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
