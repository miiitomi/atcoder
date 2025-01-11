// https://atcoder.jp/contests/abc093/tasks/arc094_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll A, B;
    cin >> A >> B;
    ll left = 0, right = 2e+18;
    while (right - left > 1) {
        __int128_t m = (left + right) / 2;
        if (m % 2 == 0) {
            __int128_t a1 = m/2, a2 = m/2 + 1, b1 = m/2, b2 = m/2 + 1;
            if (A <= a1) {
                a1++;
                a2++;
            } else if (a2 == A) {
                a2++;
            }
            if (B <= b1) {
                b1++;
                b2++;
            } else if (b2 == B) {
                b2++;
            }

            if (a1*b2 < A*B && a2*b1 < A*B) left = m;
            else right = m;
        } else {
            __int128_t a = m/2 + 1, b = m/2 + 1;
            if (A <= a) a++;
            if (B <= b) b++;
            if (a*b < A*B) left = m;
            else right = m;
        }
    }
    cout << left << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
