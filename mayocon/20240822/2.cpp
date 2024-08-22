// https://atcoder.jp/contests/abc194/tasks/abc194_c
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
    vector<ll> cnt(401, 0);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        for (ll b = 0; b <= 400; b++) {
            ll x = b-200;
            ans += cnt[b]*(a-x)*(a-x);
        }
        cnt[a+200]++;
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
