// https://atcoder.jp/contests/abc283/tasks/abc283_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, L, R;
    cin >> N >> L >> R;
    L--;
    vector<ll> A(N), B;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A[i] = a;
        for (ll b : B) a = min(a, a^b);
        for (ll &b : B) b = min(b, b^a);
        if (a) B.push_back(a);
    }
    sort(B.begin(), B.end());
    ll K = B.size();
    for (ll x = L; x < R; x++) {
        ll ans = 0;
        for (ll k = 0; k < K; k++) {
            if (x & (1LL << k)) {
                ans ^= B[k];
            }
        }
        cout << ans;
        if (x != R-1) cout << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
