// https://atcoder.jp/contests/abc258/tasks/abc258_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N), B(N), S(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        S[i] = A[i] + B[i];
        if (i > 0) S[i] += S[i-1];
    }
    ll ans = 9e+18;
    ll m = 1e+18;
    for (int i = 0; i < N; i++) {
        m = min(m, B[i]);
        ll tmp = S[i];
        if (i+1 < X) tmp += (X - (i+1)) * m;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
