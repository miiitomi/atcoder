// https://atcoder.jp/contests/abc135/tasks/abc135_c
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
    vector<ll> A(N+1);
    for (int i = 0; i <= N; i++) cin >> A[i];
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        ll y = min(x, A[i]);
        ans += y;
        x -= y;
        A[i] -= y;
        y = min(x, A[i+1]);
        ans += y;
        x -= y;
        A[i+1] -= y;
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
