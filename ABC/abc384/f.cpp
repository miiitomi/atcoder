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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> d(26, 0);

    for (int k = 0; k < 25; k++) {
        vector<ll> sum(1 << k, 0), cnt(1 << k, 0);
        for (ll a : A) {
            ll b = ((1 << k) - (a % (1 << k))) % (1 << k);
            sum[b] += a;
            cnt[b] += 1;
            d[k] += sum[a % (1 << k)] + cnt[a % (1 << k)] * a;
        }
    }

    ll ans = 0;
    for (int k = 0; k < 25; k++) {
        ans += (d[k]-d[k+1])/(1 << k);
    }
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
