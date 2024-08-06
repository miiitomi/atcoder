// https://atcoder.jp/contests/abc137/tasks/abc137_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const ll INF = 2e+18;
const ll MOD = 998244353;
using mint = modint;

mint mod_pow(mint x, int n) {
    if (n == 0) return 1;
    mint a = mod_pow(x, n/2);
    a *= a;
    if (n%2 == 1) a *= x;
    return a;
}

void solve() {
    int p;
    cin >> p;
    mint::set_mod(p);
    vector<mint> F(p, 1);
    for (int x = 1; x < p; x++) F[x] = x*F[x-1];
    vector<vector<mint>> C(p, vector<mint>(p, 1));
    for (int n = 0; n < p; n++) {
        for (int r = 0; r <= n; r++) {
            C[n][r] = F[n]/(F[n-r]*F[r]);
        }
    }
    vector<int> a(p);
    for (int i = 0; i < p; i++) cin >> a[i];

    vector<mint> b(p, 0);
    for (int j = 0; j < p; j++) {
        if (a[j] == 0) continue;
        b[0] += 1;
        for (int r = 0; r < p; r++) {
            b[r] -= C[p-1][r] * mod_pow(j, p-1-r) * (1-2*((p-1-r)%2 == 1));
        }
    }
    for (mint x : b) cout << x.val() << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
