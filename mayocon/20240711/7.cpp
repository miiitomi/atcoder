// https://atcoder.jp/contests/abc172/tasks/abc172_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 1e+15;
const ll MOD = 998244353;

map<tuple<ll,ll,ll>, ll> mp;
ll f(ll a, ll b, ll c) {
    tuple<ll,ll,ll> t{a, b, c};
    if (mp.count(t)) return mp[t];
    if ((a^b) == c) return mp[t]=0;
    if (a==0 || (((a^b)&1) != (c&1))) return mp[t]=INF;

    return mp[t] = min((f(a/2, b/2, c/2) << 1), 1+(f((a-1)/2, (b+1)/2, c/2) << 1));
}

void solve() {
    ll N;
    cin >> N;
    ll a, b, c = 0;
    cin >> a >> b;
    for (int i = 2; i < N; i++) {
        ll x;
        cin >> x;
        c ^= x;
    }
    ll ans = f(a, b, c);
    if (ans < a) cout << ans << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
