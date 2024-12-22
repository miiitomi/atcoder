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
    vector<ll> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ll h = H[i];
        for (int d = 1; i+d < N; d++) {
            ll cnt = 1, tmp = i;
            while (tmp+d < N && H[tmp+d] == h) {
                cnt++;
                tmp += d;
            }
            ans = max(ans, cnt);
        }
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
