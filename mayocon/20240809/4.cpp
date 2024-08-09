// https://atcoder.jp/contests/abc125/tasks/abc125_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> L(N), R(N);
    for (int i = 0; i < N; i++) {
        if (i == 0) L[i] = A[i];
        else L[i] = gcd(L[i-1], A[i]);
    }
    for (int i = N-1; i >= 0; i--) {
        if (i == N-1) R[i] = A[i];
        else R[i] = gcd(R[i+1], A[i]);
    }

    ll ans = -1;
    for (int i = 0; i < N; i++) {
        ll tmp;
        if (i == 0) tmp = R[1];
        else if (i == N-1) tmp = L[i-1];
        else tmp = gcd(L[i-1], R[i+1]);
        ans = max(ans, tmp);
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
