// https://atcoder.jp/contests/abc363/tasks/abc363_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll power(ll a, ll n) {
    ll ans = 1;
    for (ll k = 0; k < n; k++) ans *= a;
    return ans;
}

void solve() {
    ll N;
    cin >> N;
    for (ll k = 1; k <= 100; k++) {
        ll num;
        ll m = (k+1)/2;
        if (k == 1) num = 10;
        else num = power(10LL, m) - 1 - (power(10LL, m-1) - 1);
        if (N > num) {
            N -= num;
            continue;
        }
        string ans = string(k, '0');
        string n = to_string(N + power(10LL, m-1)-1-(k==1));
        for (ll i = 0; i < (ll)n.size(); i++) {
            ans[i] = n[i];
            ans[k-1-i] = ans[i];
        }
        cout << ans << endl;
        return;
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
