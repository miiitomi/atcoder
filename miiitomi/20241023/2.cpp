// https://atcoder.jp/contests/abc255/tasks/abc255_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll X, A, D, N;
    cin >> X >> A >> D >> N;
    ll B = A + (N-1)*D;
    if (D < 0) {
        swap(A, B);
        D *= -1;
    }

    ll left = -1, right = N;
    while (right - left > 1) {
        ll m = (left + right)/2;
        if (A + m*D >= X) {
            right = m;
        } else {
            left = m;
        }
    }

    ll ans = min(abs(X-A), abs(X-B));
    if (right < N) {
        ans = min(ans, abs(X - (A+right*D)));
    }
    right--;
    if (right >= 0) {
        ans = min(ans, abs(X - (A+right*D)));
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
