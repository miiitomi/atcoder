#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void chmax(ll &l, ll v) {
    if (l < v) l = v;
}

void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    vector<vector<ll>> dp(N+1, vector<ll>(X+1, -1));
    dp[0][X] = Y;
    ll ans = 1;

    vector<ll> v(N);
    for (int i = 0; i < N; i++) v[i] = i;
    sort(v.begin(), v.end(), [&](ll l, ll r) {return A[l] < A[r];});

    for (ll i : v) {
        vector<vector<ll>> ndp = dp;
        for (ll k = 0; k < N; k++) {
            for (ll x = 0; x <= X; x++) {
                if (dp[k][x] < 0) continue;
                chmax(ans, k+1);
                if (x >= A[i] && dp[k][x] >= B[i]) chmax(ndp[k+1][x-A[i]], dp[k][x]-B[i]);
            }
        }
        swap(dp, ndp);
    }
    for (ll k = 0; k <= N; k++) {
        for (ll x = 0; x <= X; x++) {
            if (dp[k][x] >= 0) {
                chmax(ans, k);
            }
        }
    }

    dp.assign(N+1, vector<ll>(X+1, -1));
    dp[0][X] = Y;
    sort(v.begin(), v.end(), [&](ll l, ll r) {return B[l] < B[r];});
    for (ll i : v) {
        vector<vector<ll>> ndp = dp;
        for (ll k = 0; k < N; k++) {
            for (ll x = 0; x <= X; x++) {
                if (dp[k][x] < 0) continue;
                chmax(ans, k+1);
                if (x >= A[i] && dp[k][x] >= B[i]) chmax(ndp[k+1][x-A[i]], dp[k][x]-B[i]);
            }
        }
        swap(dp, ndp);
    }
    for (ll k = 0; k <= N; k++) {
        for (ll x = 0; x <= X; x++) {
            if (dp[k][x] >= 0) {
                chmax(ans, k);
            }
        }
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
