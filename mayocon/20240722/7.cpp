// https://atcoder.jp/contests/abc191/tasks/abc191_f
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
    ll m = *min_element(A.begin(), A.end());

    map<ll,ll> mp;
    for (ll a : A) {
        vector<ll> v;
        for (ll x = 1; x*x <= a; x++) {
            if (a%x == 0) {
                v.push_back(x);
                v.push_back(a/x);
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for (ll x : v) {
            if (mp.count(x)) mp[x] = gcd(mp[x], a);
            else mp[x] = a;
        }
    }

    ll ans = 0;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        ll x = iter->first, y = iter->second;
        if (x <= m && x == y) ans++;
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
