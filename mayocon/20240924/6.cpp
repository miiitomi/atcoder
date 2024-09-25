// https://atcoder.jp/contests/abc150/tasks/abc150_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> pow2(1e+6, 1);

void solve() {
    ll N;
    cin >> N;
    vector<ll> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C.begin(), C.end());
    mint ans = 0;
    for (int i = 0; i < N; i++) {
        ll K = N-1-i;
        if (K == 0) ans += pow2[i] * C[i];
        else ans += pow2[i] * C[i] * pow2[K-1] * (K+2);
    }
    ans *= pow2[N];
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x < (int)1e+6; x++) pow2[x] = pow2[x-1]*2;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
