// https://atcoder.jp/contests/abc240/tasks/abc240_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll ans = -1e+18;
    ll a = 0, b = 0, N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        ans = max(ans, a+b+x);
        ans = max(ans, a + y*b + (y*(y+1)/2)*x);
        if (b > 0 && x < 0) {
            ll left = 0, right = ((ll)9e+18) / abs(x);
            while (right - left > 1) {
                ll m = (right + left) / 2;
                ll z = b + m * x;
                if (z >= 0) left = m;
                else right = m;
            }
            left = min(left, y);
            ans = max(ans, a + left*b + (left*(left+1)/2)*x);
        }
        a = a + y*b + (y*(y+1)/2)*x;
        b = b + y*x;
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
