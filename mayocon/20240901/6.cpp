// https://atcoder.jp/contests/abc196/tasks/abc196_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    ll l = -1e+9, r = 1e+9, L = -1e+9, R = 1e+9;
    while (N--) {
        ll a, t;
        cin >> a >> t;
        if (t == 1) {
            L += a;
            R += a;
        } else if (t == 2) {
            if (a <= L) {
                continue;
            } else if (a >= R) {
                l = 1e+9; r = 1e+9; L = a; R = a;
            } else {
                l = a - L + l;
                L = a;
            }
        } else {
            if (a <= L) {
                l = 1e+9; r = 1e+9; L = a; R = a;
            } else if (a >= R) {
                continue;
            } {
                r = a - L + l;
                R = a;
            }
        }
    }
    ll Q;
    cin >> Q;
    while (Q--) {
        ll x;
        cin >> x;
        if (x <= l) cout << L << "\n";
        else if (x >= r) cout << R << "\n";
        else cout << L + (x - l) << "\n";
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
