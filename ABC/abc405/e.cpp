#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(1e+7, 1);
mint comb(int n, int r) {
    if (r > n) return 0;
    return F[n]/(F[r]*F[n-r]);
}

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    mint ans = 0;
    for (int i = 0; i <= B; i++) {
        int a = A-1, b = B-i;
        mint tmp = comb(a+b, a);
        tmp *= comb(D+i+C, C);
        ans += tmp;
    }
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x < 1e+7; x++) F[x] = F[x-1]*x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
