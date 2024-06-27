// https://atcoder.jp/contests/abc311/tasks/abc311_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, D;
    cin >> N >> D;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int ans = 0;
    for (int i = 0; i < D; i++) {
        for (int d = i; d < D; d++) {
            int cnt = 0;
            for (int k = 0; k < N; k++) {
                cnt += (S[k][d] == 'o');
            }
            if (cnt == N) {
                ans = max(ans, d+1-i);
            } else {
                break;
            }
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
