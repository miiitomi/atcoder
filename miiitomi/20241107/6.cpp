// https://atcoder.jp/contests/abc217/tasks/abc217_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(5001, 1), I(5001, 1);
mint P(int n, int r) {
    if (r > n) return 0;
    return F[n]/(F[n-r]);
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<mint> tmp(N+1, 1);
    for (int k = 1; k <= N; k++) {
        mint p1 = P(k, N/M), p2 = P(k, N/M+1);
        for (int r = 0; r < M; r++) {
            if (r < N%M) tmp[k] *= p2;
            else tmp[k] *= p1;
        }
        mint tmp2 = 1;
        for (int i = 1; i < k; i++) {
            tmp2 *= k-i+1;
            tmp[k] -= tmp[i] * tmp2 * I[i];
        }
    }
    for (int k = 1; k <= N; k++) {
        mint ans = tmp[k] / F[k];
        cout << ans.val() << "\n";
    }
}

int main() {
    for (int x = 1; x <= 5000; x++) {
        F[x] = x*F[x-1];
        I[x] = F[x].inv();
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
