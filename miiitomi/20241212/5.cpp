// https://atcoder.jp/contests/abc086/tasks/arc089_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> S(4*K+1, vector<ll>(4*K+1, 0));
    while (N--) {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        x %= 2*K;
        y %= 2*K;
        int l0 = 2*K-K+1+x, r0 = 2*K+x;
        int l1 = r0+1;
        int r1 = l1 + K-1;
        if (r1 >= 4*K) {
            l1 -= 2*K;
            r1 -= 2*K;
        }
        int b0 = 2*K-K+1+y, t0 = 2*K+y;
        int b1 = t0+1;
        int t1 = b1 + K-1;
        if (t1 >= 4*K) {
            b1 -= 2*K;
            t1 -= 2*K;
        }
        if (c == 'B') {
            swap(b0, b1);
            swap(t0, t1);
        }
        S[l0][b0]++;
        S[l0][t0+1]--;
        S[r0+1][b0]--;
        S[r0+1][t0+1]++;

        S[l1][b1]++;
        S[l1][t1+1]--;
        S[r1+1][b1]--;
        S[r1+1][t1+1]++;
    }
    for (int i = 0; i <= 4*K; i++) {
        for (int j = 0; j < 4*K; j++) {
            S[i][j+1] += S[i][j];
        }
    }
    for (int j = 0; j <= 4*K; j++) {
        for (int i = 0; i < 4*K; i++) {
            S[i+1][j] += S[i][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < 2*K; i++) {
        for (int j = 0; j < 2*K; j++) {
            ll tmp = 0;
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    tmp += S[2*K*k+i][2*K*l+j];
                }
            }
            ans = max(ans, tmp);
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
