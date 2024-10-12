#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> bool chmin(T &v, T nv) {
    if (v > nv) {
        v = nv;
        return true;
    }
    return false;
}

void solve() {
    ll N;
    cin >> N;
    ll sum = 0;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        sum += B[i];
    }
    if (sum % 3 != 0) {
        cout << -1 << endl;
        return;
    }
    sum /= 3;
    vector<vector<ll>> dp(sum+1, vector<ll>(sum+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        vector<vector<ll>> ndp(sum+1, vector<ll>(sum+1, INF));
        for (int a = 0; a <= sum; a++) {
            for (int b = 0; b <= sum; b++) {
                if (dp[a][b] == INF) continue;
                if (a+B[i] <= sum) chmin(ndp[a+B[i]][b], dp[a][b] + (A[i] != 0));
                if (b+B[i] <= sum) chmin(ndp[a][b+B[i]], dp[a][b] + (A[i] != 1));
                chmin(ndp[a][b], dp[a][b] + (A[i] != 2));
            }
        }
        swap(dp, ndp);
    }
    if (dp[sum][sum] == INF) cout << -1 << endl;
    else cout << dp[sum][sum] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
