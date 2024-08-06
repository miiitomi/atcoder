// https://atcoder.jp/contests/abc188/tasks/abc188_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, C;
    cin >> N >> C;
    vector<ll> v;
    vector<ll> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
        b[i]++;
        v.push_back(a[i]);
        v.push_back(b[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) a[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), a[i]));
    for (int i = 0; i < N; i++) b[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), b[i]));
    ll M = v.size();
    vector<ll> tmp(M, 0);
    for (int i = 0; i < N; i++) {
        tmp[a[i]] += c[i];
        tmp[b[i]] -= c[i];
    }
    for (int i = 0; i < M-1; i++) {
        tmp[i+1] += tmp[i];
    }
    ll ans = 0;
    for (int i = 0; i < M-1; i++) {
        ll cost = min(C, tmp[i]);
        ll days = v[i+1] - v[i];
        ans += cost * days;
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
