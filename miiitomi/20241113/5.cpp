// https://atcoder.jp/contests/abc146/tasks/abc146_e
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
    vector<ll> A(N), S(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[i+1] = S[i] + A[i];
    }
    map<ll, ll> mp;
    for (int i = 0; i <= N; i++) {
        S[i] = (S[i] - i + N*K) % K;
    }
    ll ans = 0;
    int j = 0;
    for (int i = 0; i < N; i++) {
        while (j <= N && j-i <= K-1) {
            mp[S[j]]++;
            j++;
        }
        mp[S[i]]--;
        ans += mp[S[i]];
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
