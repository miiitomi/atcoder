// https://atcoder.jp/contests/abc197/tasks/abc197_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = INF;
    for (ll s = 0; s < (1 << (N-1)); s++) {
        ll tmp_xor = 0, tmp_or = 0;
        for (int i = 0; i < N; i++) {
            tmp_or |= A[i];
            if ((i == N-1) || (s & (1 << i))) {
                tmp_xor ^= tmp_or;
                tmp_or = 0;
            }
        }
        ans = min(ans, tmp_xor);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
