// https://atcoder.jp/contests/typical90/tasks/typical90_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, L, K;
    cin >> N >> L >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> B(N+1);
    for (int i = 0; i <= N; i++) {
        if (i == 0) B[i] = A[i];
        else if (i < N) B[i] = A[i]-A[i-1];
        else B[i] = L - A[i-1];
    }
    ll left = 1, right = L;
    while (right - left > 1) {
        ll m = (left + right)/2;
        vector<ll> v;
        for (ll b : B) {
            if (v.empty() || v.back() >= m) v.push_back(b);
            else v.back() += b;
        }
        if (v.back() < m) v.pop_back();
        if (v.size() >= K+1) left = m;
        else right = m;
    }
    cout << left << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
