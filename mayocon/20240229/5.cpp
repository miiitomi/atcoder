// https://atcoder.jp/contests/abc285/tasks/abc285_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> B(N, 0);
    for (ll d = 1; d < N; d++) {
        ll e = d;
        ll cnt = 0;
        for (ll x = 0; ; x++) {
            if (e >= 2) {
                cnt += 2 * A[x];
                e -= 2;
            } else if (e >= 1) {
                cnt += A[x];
                e -= 1;
            }
            if (e == 0) break;
        }
        B[d] = cnt;
    }

    vector<ll> ans(N+1, 0);
    for (int i = 0; i < N; i++) {
        for (int d = 0; i+d+1 <= N; d++) {
            ans[i+d+1] = max(ans[i+d+1], ans[i] + B[d]);
        }
    }

    cout << ans.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
