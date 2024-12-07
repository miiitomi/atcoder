// https://atcoder.jp/contests/abc158/tasks/abc158_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    ll ans = 0;
    ll r = N / (A + B);
    ans += r * A;
    N %= (A + B);
    ans += min(A, N);
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
