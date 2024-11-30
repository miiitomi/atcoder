// https://atcoder.jp/contests/abc052/tasks/arc067_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> cnt(N+1, 0);
    for (ll x = 1; x <= N; x++) {
        ll X = x;
        for (ll y = 2; y <= x; y++) {
            while (X % y == 0) {
                X /= y;
                cnt[y]++;
            }
        }
    }
    mint ans = 1;
    for (ll a : cnt) ans *= a+1;
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
