// https://atcoder.jp/contests/abc110/tasks/abc110_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(1e+6, 1);
mint C(int n, int r) {
    return F[n]/(F[n-r]*F[r]);
}
mint H(int n, int r) {return C(n+r-1, r);}

void solve() {
    ll N, M;
    cin >> N >> M;
    mint ans = 1;
    for (ll x = 2; x*x <= M; x++) {
        if (M%x != 0) continue;
        ll cnt = 0;
        while (M%x == 0) {
            cnt++;
            M /= x;
        }
        ans *= H(N, cnt);
    }
    if (M != 1) ans *= N;
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x < 1e+6; x++) F[x] = F[x-1]*x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
