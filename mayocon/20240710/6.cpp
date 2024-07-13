// https://atcoder.jp/contests/abc154/tasks/abc154_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F((ll)2e+6 + 10, 1);
mint Binomial(int n, int r) {return F[n]/(F[n-r]*F[r]);};

mint f(int R, int C) {
    return (Binomial(C+R+2, R+2)*(R+2)-C-1)/(C+1);
}

void solve() {
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    mint ans = f(r2,c2)-f(r2,c1-1)-f(r1-1,c2)+f(r1-1,c1-1);
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x < (ll)2e+6 + 10; x++) F[x] = F[x-1]*x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
