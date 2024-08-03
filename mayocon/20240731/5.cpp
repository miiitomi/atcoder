// https://atcoder.jp/contests/abc298/tasks/abc298_f
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
    map<pair<ll,ll>, ll> mp;
    map<ll, ll> R, C;
    for (int i = 0; i < N; i++) {
        ll r, c, x;
        cin >> r >> c >> x;
        mp[{r, c}] = x;
        R[r] += x;
        C[c] += x;
    }
    vector<pair<ll,ll>> V;
    for (auto iter = C.begin(); iter != C.end(); iter++) V.push_back({iter->second, iter->first});
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    ll ans = -INF;
    for (auto iter = R.begin(); iter != R.end(); iter++) {
        ll r = iter->first, tmp = iter->second;
        for (pair<ll,ll> &p : V) {
            ll c = p.second;
            if (!mp.count({r, c})) {
                ans = max(ans, tmp + p.first);
                break;
            } else {
                ans = max(ans, tmp + p.first - mp[{r, c}]);
            }
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
