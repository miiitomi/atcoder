// https://atcoder.jp/contests/abc202/tasks/abc202_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N+1, 0), B(N+1, 0), C(N+1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    for (int i = 1; i <= N; i++) cin >> C[i];
    vector<ll> cnt(N+1, 0);
    for (int j = 1; j <= N; j++) {
        cnt[B[C[j]]]++;
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += cnt[A[i]];
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
