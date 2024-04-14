// https://atcoder.jp/contests/abc176/tasks/abc176_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X, T;
    cin >> N >> X >> T;
    int cnt = 0;
    while (N > 0) {
        cnt += T;
        N -= X;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
