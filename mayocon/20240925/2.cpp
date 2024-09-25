// https://atcoder.jp/contests/abc369/tasks/abc369_c
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
    vector<ll> A(N), B(N-1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i >= 1) B[i-1] = A[i]-A[i-1];
    }
    ll ans = 0;
    ll r = 0;
    for (ll l = 0; l < N; l++) {
        while (r <= l && r <= N-2) r++;
        while (r <= N-2 && B[l] == B[r]) r++;
        ans += (r - l + 1);
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
