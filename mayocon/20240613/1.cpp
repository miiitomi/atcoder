// https://atcoder.jp/contests/abc324/tasks/abc324_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    int mi = 1e+9, ma = -1;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        mi = min(mi, a);
        ma = max(ma, a);
    }

    if (mi == ma) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
