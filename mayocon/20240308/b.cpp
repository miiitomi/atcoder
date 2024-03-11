// https://atcoder.jp/contests/abc115/tasks/abc115_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];
    sort(h.begin(), h.end());
    int ans = 2e+9;
    for (int i = 0; i+K-1 <= N-1; i++) {
        ans = min(ans, h[i+K-1] - h[i]);
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
