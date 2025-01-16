// https://atcoder.jp/contests/abc151/tasks/abc151_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(1e+6, 1);
mint C(int n, int r) {return F[n]/(F[n-r]*F[r]);}

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    mint ans = 0;
    for (int i = 0; i < N; i++) {
        ll l = i, r = N-1-i;
        if (l >= K-1) ans += A[i]*C(l, K-1);
        if (r >= K-1) ans -= A[i]*C(r, K-1);
    }
    cout << ans.val() << "\n";
}

int main() {
    for (int x = 1; x < 1e+6; x++) {
        F[x] = F[x-1]*x;
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
