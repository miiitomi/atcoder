// https://atcoder.jp/contests/abc191/tasks/abc191_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    map<ll, ll> mp;
    for (ll a : A) {
        vector<ll> v;
        for (ll x = 1; x*x <= a; x++) {
            if (a % x == 0) {
                v.push_back(x);
                v.push_back(a / x);
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (ll x : v) {
            if (mp.count(x)) mp[x] = gcd(a, mp[x]);
            else mp[x] = a;
        }
    }

    ll m = *min_element(A.begin(), A.end());
    ll ans = 0;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        if (iter->first > m) break;
        if (iter->second == iter->first) ans++;
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
