// https://atcoder.jp/contests/abc182/tasks/abc182_d
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
    ll ans = 0;
    ll x = 0;
    ll sum = 0, mv = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        mv = max(mv, sum);
        ans = max(ans, x+mv);
        x += sum;
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
