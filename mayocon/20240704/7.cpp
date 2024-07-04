// https://atcoder.jp/contests/abc291/tasks/abc291_g
#include <bits/stdc++.h>
#include <atcoder/convolution>
using namespace std;
using namespace atcoder;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(2*N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[N+i] = A[i];
    }
    for (int i = 0; i < N; i++) cin >> B[i];
    reverse(B.begin(), B.end());
    vector<ll> C(N, 0);
    for (ll k = 0; k < 5; k++) {
        vector<ll> a0(2*N, 0), b0(N, 0);
        for (int i = 0; i < 2*N; i++) {
            if (!(A[i] & (1LL << k))) a0[i] = 1;
        }
        for (int i = 0; i < N; i++) {
            if (!(B[i] & (1LL << k))) b0[i] = 1;
        }

        vector<ll> c0 = convolution_ll(a0, b0);
        for (int i = 0; i < N; i++) {
            C[i] += (1LL << k) * (N - c0[N-1+i]);
        }
    }
    ll ans = *max_element(C.begin(), C.end());
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
