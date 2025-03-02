#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, X;
    cin >> N >> X;
    ll right = INF;
    vector<ll> U(N), D(N);
    for (int i = 0; i < N; i++) {
        cin >> U[i] >> D[i];
        right = min(U[i]+D[i], right);
    }
    right++;
    ll left = 2;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        vector<ll> H(N, 0);
        bool ok = true;
        for (int i = 0; i < N && ok; i++) {
            if (D[i] < m) {
                H[i] = m-D[i];
                if (H[i] > U[i]) ok = false;
            }
        }

        if (!ok) {
            right = m;
            continue;
        }

        vector<ll> dp1 = H, dp2 = U;
        for (int i = 0; i < N-1 && ok; i++) {
            ll a = dp1[i+1], b = dp2[i+1];
            ll c = dp1[i]-X, d = dp2[i] + X;
            if (b < c || d < a) ok = false;
            else {
                dp1[i+1] = max(a, c);
                dp2[i+1] = min(b, d);
            }
        }

        if (ok) left = m;
        else right = m;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) ans += U[i]+D[i]-left;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
