// https://atcoder.jp/contests/abc152/tasks/abc152_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 1e+9 + 7;

template<typename T> T mod_pow(T a, ll n) {
    if (n == 0) return 1;
    T res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    return res * res;
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll &a : A) cin >> a;
    map<ll, ll> mp;
    vector<map<ll,ll>> v(N);
    for (int i = 0; i < N; i++) {
        ll a = A[i];
        for (ll x = 2; x*x <= a; x++) {
            if (a%x != 0) continue;
            ll cnt = 0;
            while (a%x == 0) {
                a /= x;
                cnt++;
            }
            v[i][x] = cnt;
            if (mp.contains(x)) mp[x] = max(mp[x], cnt);
            else mp[x] = cnt;
        }
        if (a != 1) {
            v[i][a] = 1;
            if (mp.contains(a)) mp[a] = max(mp[a], 1LL);
            else mp[a] = 1;
        }
    }
    mint ans = 0;
    mint tmp = 1;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        mint a = (mint)(iter->first);
        ll n = iter->second;
        tmp *= mod_pow(a, n);
    }
    for (int i = 0; i < N; i++) {
        mint tmp2 = tmp;
        for (auto iter = v[i].begin(); iter != v[i].end(); iter++) {
            mint a = (mint)(iter->first);
            ll n = iter->second;
            tmp2 /= mod_pow(a, n);
        }
        ans += tmp2;
    }
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
