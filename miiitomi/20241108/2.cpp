// https://atcoder.jp/contests/abc092/tasks/arc093_a
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
    vector<ll> A(N+2, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];
    ll sum = 0;
    for (int i = 0; i <= N; i++) sum += abs(A[i]-A[i+1]);
    for (int i = 1; i <= N; i++) {
        cout << sum - abs(A[i-1]-A[i]) - abs(A[i]-A[i+1]) + abs(A[i-1]-A[i+1]) << "\n";
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
