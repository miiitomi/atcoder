// https://atcoder.jp/contests/abc266/tasks/abc266_g
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<mint> F(1e+7, 1);
mint C(int n, int r) {return F[n]/(F[n-r]*F[r]);}
mint H(int n, int r) {return C(n+r-1, r);}

void solve() {
    int r, g, b, k;
    cin >> r >> g >> b >> k;
    r -= k;
    g -= k;
    mint ans = C(g+b+k, g) * C(b+k, b);
    ans *= H(b+k+1, r);
    cout << ans.val() << endl;
}

int main() {
    for (int x = 2; x < 1e+7; x++) F[x] = F[x-1] * x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
