// https://atcoder.jp/contests/abc281/tasks/abc281_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll rec(vector<ll> &a, ll k) {
    if (k < 0) return 0;

    vector<ll> b, c;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] & (1LL << k)) b.push_back(a[i]%(1LL << k));
        else c.push_back(a[i]%(1LL << k));
    }

    if ((ll)b.size() > (ll)c.size()) swap(b, c);

    if ((ll)b.size() == 0) {
        return rec(c, k-1);
    }

    return (1LL << k) + min(rec(b, k-1), rec(c, k-1));
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    ll ans = rec(a, 32);
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
