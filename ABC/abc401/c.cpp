#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N+1, 1);
    ll sum = K;
    for (int i = K; i <= N; i++) {
        A[i] = sum;
        sum = (sum + A[i] - A[i-K] + (ll)1e+9) % ((ll)1e+9);
    }
    cout << A.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
