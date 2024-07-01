// https://atcoder.jp/contests/abc284/tasks/abc284_g
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint;
using ll = long long;

mint mod_pow(mint a, ll n) {
    if (n == 0) return 1;
    mint res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    else return res * res;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    mint::set_mod(M);

    mint ans = 0, p = N-1;
    for (ll l = 2; l <= N; l++) {
        ans += p*mod_pow(N, N-l)*(l*(l-1)/2);
        p *= N-l;
    }
    ans *= N;
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
