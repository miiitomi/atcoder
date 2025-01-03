// https://atcoder.jp/contests/typical90/tasks/typical90_ad
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<bool> is_prime(N+1, true);
    vector<ll> cnt(N+1, 0);
    for (ll x = 2; x <= N; x++) {
        if (!is_prime[x]) continue;
        cnt[x] = 1;
        for (ll y = 2*x; y <= N; y += x) {
            cnt[y]++;
            is_prime[y] = false;
        }
    }
    ll ans = 0;
    for (ll x = 2; x <= N; x++) ans += (cnt[x] >= K);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
