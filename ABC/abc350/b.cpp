#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> v(N+1, 1);
    v[0] = 0;
    while (Q--) {
        int t;
        cin >> t;
        if (v[t]) v[t] = 0;
        else v[t] = 1;
    }
    int ans = 0;
    for (int t = 1; t <= N; t++) ans += v[t];
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
