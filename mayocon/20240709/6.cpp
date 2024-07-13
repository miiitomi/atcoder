// https://atcoder.jp/contests/abc150/tasks/abc150_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> T mod_pow(T a, ll n) {
    if (n == 0) return 1;
    T res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    return res * res;
}

void solve() {
    int N;
    cin >> N;
    vector<ll> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());
    mint ans = 0;
    for (int k = 0; k < N; k++) ans += ((mint)C[k])*((mint)(k+2));
    ans *= mod_pow((mint)(2), 2*N-2);
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
