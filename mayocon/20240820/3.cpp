// https://atcoder.jp/contests/abc334/tasks/abc334_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll A, M, L, R;
    cin >> A >> M >> L >> R;
    ll l = L, r = R;

    if (abs(l-A) % M != 0) {
        if (l < A) {
            l += (A-l) % M;
        } else {
            l += M - (l-A)%M;
        }
    }

    if (abs(r-A) % M != 0) {
        if (r < A) {
            r -= M - (A-r)%M;
        } else {
            r -= (r-A)%M;
        }
    }

    cout << (r-l)/M + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
