// https://atcoder.jp/contests/abc057/tasks/abc057_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll C(ll n, ll r) {
    if (r == 0 || n == r) return 1;
    return C(n-1, r-1)*n/r;
}

void solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll sum = 0;
    for (int i = 0; i < A; i++) sum += v[i];

    cout << (double)sum/A << endl;
    ll k = 0, l = 0;
    ll x = v[A-1];
    for (int i = 0; i < N; i++) {
        if (v[i] > x) k++;
        else if (v[i] == x) l++;
    }

    if (sum % A != 0 || (sum/A) != x) {
        cout << C(l, A-k) << endl;
    } else {
        ll ans = 0;
        for (ll y = A; y <= B; y++) ans += C(l, y-k);
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
