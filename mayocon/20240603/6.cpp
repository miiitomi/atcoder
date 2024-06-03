// https://atcoder.jp/contests/abc172/tasks/abc172_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint1000000007;

vector<mint> F(1e+6, 1);
mint P(int n, int r) {return F[n]/F[n-r];}
mint C(int n, int r) {return F[n]/(F[n-r]*F[r]);}

void solve() {
    int N, M;
    cin >> N >> M;
    mint ans = 0;
    for (int k = 0; k <= N; k++) {
        mint tmp = C(N, k) * P(M, k) * P(M-k, N-k) * P(M-k, N-k);
        if (k % 2 == 0) ans += tmp;
        else ans -= tmp;
    }
    cout << ans.val() << "\n";
}

int main() {
    for (int x = 1; x < 1e+6; x++) F[x] = x * F[x-1];
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
