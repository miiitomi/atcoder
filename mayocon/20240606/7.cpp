// https://atcoder.jp/contests/abc205/tasks/abc205_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

vector<mint> F(1e+7, 1);
mint C(int n, int r) {return F[n]/(F[n-r]*F[r]);}

void solve() {
    int N, M, K;
    cin >> N >> M >> K;

    if (N > M+K) {
        cout << 0 << "\n";
        return;
    }

    mint ans = C(N+M, M);
    if (K < N) ans -= C(M+N, N-(K+1));
    cout << ans.val() << "\n";
}

int main() {
    for (int x = 1; x < 1e+7; x++) F[x] = F[x-1] * x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
