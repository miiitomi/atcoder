// https://atcoder.jp/contests/abc182/tasks/abc182_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> A;
map<pair<ll, ll>, ll> mp;

ll f(ll X, ll i) {
    if (mp.contains(make_pair(X, i))) return mp[make_pair(X, i)];
    if (i == N-1) return mp[make_pair(X, i)] = 1;
    if (X % A[i+1] == 0) return mp[make_pair(X, i)] = f(X, i+1);
    return mp[make_pair(X, i)] = f(X - (X % A[i+1]), i+1) + f(X + A[i+1]-(X % A[i+1]), i+1);
}

void solve() {
    ll X;
    cin >> N >> X;
    A.resize(N);
    for (ll &a : A) cin >> a;
    cout << f(X, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
