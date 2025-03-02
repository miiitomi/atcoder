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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll M = *max_element(A.begin(), A.end());
    vector<ll> cnt(M+1, 0);
    for (auto &a : A) cnt[a]++;
    vector<ll> dp(M + 1, 0), ep(M, 1);
    for (int x = 1; x <= M; x++) {
        for (int y = x; y <= M; y += x) {
            dp[x] += cnt[y];
        }
    }
    for (int x = 1; x <= M; x++) {
        for (int y = x; y <= M; y += x) {
            if (dp[x] >= K) ep[y] = x;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ep[A[i]] << "\n";
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
