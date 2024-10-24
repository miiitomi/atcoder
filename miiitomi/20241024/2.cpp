// https://atcoder.jp/contests/abc060/tasks/arc073_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, T;
    cin >> N >> T;
    vector<ll> t(N);
    vector<ll> v;
    for (int i = 0; i < N; i++) {
        cin >> t[i];
        v.push_back(t[i]);
        v.push_back(t[i] + T);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<ll> cnt(v.size(), 0);
    for (ll &x : t) {
        cnt[distance(v.begin(), lower_bound(v.begin(), v.end(), x))]++;
        cnt[distance(v.begin(), lower_bound(v.begin(), v.end(), x+T))]--;
    }
    ll ans = 0;
    for (int i = 0; i < (int)cnt.size()-1; i++) {
        if (cnt[i] >= 1) ans += v[i+1]-v[i];
        cnt[i+1] += cnt[i];
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
