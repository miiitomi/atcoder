#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> X(N), H(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> H[i];

    bool can_see_from_zero = true;
    for (int i = 1; i < N; i++) {
        if (H[i-1]*X[i] >= H[i]*X[i-1]) {
            can_see_from_zero = false;
            break;
        }
    }
    if (can_see_from_zero) {
        cout << -1 << "\n";
        return;
    }

    double ans = 0;
    for (int i = 1; i < N; i++) {
        ans = max(ans, (H[i-1]*X[i] - H[i]*X[i-1])/(X[i]-X[i-1]+0.0));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(18);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
