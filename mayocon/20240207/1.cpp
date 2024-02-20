// https://atcoder.jp/contests/abc181/tasks/abc181_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, ans = 0;
    cin >> N;
    while (N--) {
        ll a, b;
        cin >> a >> b;
        ans += (a + b) * (b - a + 1) / 2;
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
