// https://atcoder.jp/contests/abc166/tasks/abc166_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll X;
    cin >> X;
    for (ll a = 0; a <= 1e+5; a++) {
        ll Y = a*a*a*a*a - X;
        if (Y == 0) {
            cout << a << " " << 0 << "\n";
            return;
        } else if (Y > 0) {
            for (ll b = 0; b*b*b*b*b <= Y; b++) {
                if (b*b*b*b*b == Y) {
                    cout << a << " " << b << "\n";
                    return;
                }
            }
        } else {
            for (ll b = 0; b*b*b*b*b >= Y; b--) {
                if (b*b*b*b*b == Y) {
                    cout << a << " " << b << "\n";
                    return;
                }
            }
        }
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
