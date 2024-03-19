// https://atcoder.jp/contests/abc135/tasks/abc135_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N+1), B(N);
    for (int i = 0; i < N+1; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll x = min(A[i], B[i]);
        ans += x;
        A[i] -= x;
        B[i] -= x;

        x = min(A[i+1], B[i]);
        ans += x;
        A[i+1] -= x;
        B[i] -= x;
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
