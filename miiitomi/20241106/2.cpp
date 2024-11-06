// https://atcoder.jp/contests/code-festival-2017-qualc/tasks/code_festival_2017_qualc_b
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
    ll ans = 1, tmp = 1;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        ans *= 3;
        if (a % 2 == 1) tmp *= 1;
        else tmp *= 2;
    }
    ans -= tmp;
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
