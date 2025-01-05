#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll p(ll x, ll n) {
    ll ans = 1;
    for (int k = 0; k < n; k++) ans *= x;
    return ans;
}

ll f(ll N) {
    if (N < 10) return 0;
    string S = to_string(N);
    ll K = S.size(), ans = 0;
    for (int k = 2; k <= K-1; k++) {
        for (int x = 1; x <= 9; x++) {
            ans += p(x, k-1);
        }
    }

    for (ll x = 1; x < (S[0] - '0'); x++) {
        ans += p(x, K-1);
    }
    for (int k = 1; k < K; k++) {
        ll y = S[0] - '0';
        for (ll x = 0; x < min(S[0]-'0', S[k]-'0'); x++) {
            ans += p(y, K-1-k);
        }
        if (S[k] < S[0]) {
            if (k == K-1) ans++;
        } else {
            break;
        }
    }
    return ans;
}

void solve() {
    ll L, R;
    cin >> L >> R;
    cout << f(R) - f(L-1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
