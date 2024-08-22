// https://atcoder.jp/contests/abc313/tasks/abc313_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, m = 0;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        m += A[i];
    }
    m /= N;

    ll ans = INF;
    for (ll x = m-2; x <= m+2; x++) {
        ll tmp1 = 0, tmp2 = 0;
        for (ll a : A) {
            if (a < x) tmp1 += x-a;
            else if (x+1 <= a) tmp2 += a-(x+1);
        }
        ans = min(ans, max(tmp1, tmp2));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
