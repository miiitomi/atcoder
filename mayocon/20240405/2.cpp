// https://atcoder.jp/contests/abc212/tasks/abc212_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int ans = 2e+9;
    while (M--) {
        int b;
        cin >> b;
        auto iter = lower_bound(A.begin(), A.end(), b);
        if (iter != A.end()) {
            ans = min(ans, abs(*iter - b));
        }
        if (iter != A.begin()) {
            iter--;
            ans = min(ans, abs(*iter - b));
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
