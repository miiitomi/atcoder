// https://atcoder.jp/contests/abc240/tasks/abc240_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    ll ans = -INF;
    ll B = 0, A = 0;
    for (int i = 0; i < N; i++) {
        ll b1 = B + x[i], b2 = y[i]*B + x[i]*(y[i]*(y[i]+1))/2;
        ans = max(ans, A + b1);
        ans = max(ans, A + b2);
        if ((B + x[i] >= 0) != (B + y[i]*x[i] >= 0)) {
            ll l = 1, r = y[i];
            while (r - l > 1) {
                ll m = (r+l)/2;
                ll b = B + m*x[i];
                if ((b1 >= 0) == (b >= 0)) l = m;
                else r = m;
            }
            ll b = l*B + x[i]*(l*(l+1))/2;
            ans = max(ans, A + b);
            b = r*B + x[i]*(r*(r+1))/2;
            ans = max(ans, A + b);
        }
        B += x[i]*y[i];
        A += b2;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
