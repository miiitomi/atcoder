// https://atcoder.jp/contests/abc046/tasks/arc062_a
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
    ll t = 1, a = 1;
    while (N--) {
        ll T, A;
        cin >> T >> A;
        ll p = max((t+T-1)/T, (a+A-1)/A);
        t = p*T;
        a = p*A;
    }
    cout << t+a << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
