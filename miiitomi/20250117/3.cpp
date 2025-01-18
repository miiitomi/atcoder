// https://atcoder.jp/contests/abc190/tasks/abc190_f
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
    fenwick_tree<ll> ft(N);
    vector<ll> A(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        ans += ft.sum(A[i]+1, N);
        ft.add(A[i], 1);
    }
    for (int i = 0; i < N; i++) {
        cout << ans << "\n";
        ans += (N-1 - A[i]) - A[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
