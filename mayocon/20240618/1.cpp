// https://atcoder.jp/contests/abc152/tasks/abc152_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    int m = 1e+9, ans = 0;
    for (int i = 0; i < N; i++) {
        if (m >= P[i]) ans++;
        m = min(m, P[i]);
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
