// https://atcoder.jp/contests/abc266/tasks/abc266_b
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
    if (N%MOD == 0) {
        cout << 0 << endl;
    } else if (N > 0) {
        cout << N%MOD << endl;
    } else {
        cout << MOD - (-N)%MOD << endl;
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
