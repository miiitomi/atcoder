// https://atcoder.jp/contests/abc354/tasks/abc354_a
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll H;
    cin >> H;
    ll x = 0, y = 1;
    for (ll i = 0; i < 1000; i++) {
        if (x > H) {
            cout << i << "\n";
            return;
        }
        x += y;
        y *= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
