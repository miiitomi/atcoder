// https://atcoder.jp/contests/abc297/tasks/abc297_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    while (a != b) {
        if (a > b) swap(a, b);
        if (b % a == 0) {
            ans += b / a - 1;
            b = a;
        } else {
            ans += b / a;
            b %= a;
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
