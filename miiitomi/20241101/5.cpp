// https://atcoder.jp/contests/abc297/tasks/abc297_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<mint> F(H*W+1, 1), C(H*W+1, 0);
    for (int x = 1; x <= H*W; x++) F[x] = F[x-1]*x;
    for (int n = K; n <= H*W; n++) C[n] = F[n]/(F[n-K]*F[K]);
    mint ans = 0;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            mint tmp = C[H*W];
            tmp -= C[(h-1)*W];
            tmp -= C[(H-h)*W];
            tmp -= C[H*(w-1)];
            tmp -= C[H*(W-w)];
            tmp += C[(h-1)*(w-1)];
            tmp += C[(h-1)*(W-w)];
            tmp += C[(H-h)*(w-1)];
            tmp += C[(H-h)*(W-w)];
            ans += tmp;
        }
    }
    ans *= C[H*W].inv();
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
