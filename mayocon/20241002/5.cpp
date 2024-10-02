// https://atcoder.jp/contests/abc161/tasks/abc161_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<ll> f(ll N) {
    vector<ll> v;
    for (ll x = 1; x*x <= N; x++) {
        if (N%x == 0) {
            if (x >= 2) v.push_back(x);
            if (N/x >= 2) v.push_back(N/x);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

void solve() {
    ll N;
    cin >> N;
    if (N == 2) {
        cout << 1 << endl;
        return;
    }
    vector<ll> v = f(N);
    vector<ll> w = f(N-1);
    for (ll x : w) v.push_back(x);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll ans = 0;
    for (ll x : v) {
        ll M = N;
        while (M%x == 0) M /= x;
        ll y = M % x;
        ans += (y == 1);
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
