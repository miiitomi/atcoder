// https://atcoder.jp/contests/abc119/tasks/abc119_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 1e+18;
const ll MOD = 998244353;

ll f(ll A, vector<ll> a) {
    if (a.empty()) return INF;
    ll m = 0;
    for (ll x : a) m += x;
    return 10*((int)a.size() - 1) + abs(m - A);
}

void solve() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<ll> l(N);
    for (int i = 0; i < N; i++) cin >> l[i];
    ll M = (1 << N) * (1 << N);
    ll ans = INF;
    for (ll x = 0; x < M; x++) {
        ll y = x;
        vector<ll> a, b, c;
        for (int i = 0; i < N; i++) {
            if (y%4 == 0) a.push_back(l[i]);
            else if (y%4 == 1) b.push_back(l[i]);
            else if (y%4 == 2) c.push_back(l[i]);
            y /= 4;
        }
        ll tmp = f(A, a) + f(B, b) + f(C, c);
        ans = min(ans, tmp);
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
