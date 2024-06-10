// https://atcoder.jp/contests/abc194/tasks/abc194_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    int ans = 1e+9;
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            if (a == b) {
                ans = min(ans, A[a] + B[b]);
            } else {
                ans = min(ans, max(A[a], B[b]));
            }
        }
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
