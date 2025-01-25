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
    vector<vector<ll>> B(N+2);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[A[i]].push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll a = A[i];
        ll l = (i+1);
        if (!B[a-1].empty()) {
            auto iter = lower_bound(B[a-1].begin(), B[a-1].end(), i);
            if (iter != B[a-1].begin()) {
                iter--;
                l = i - *iter;
            }
        }
        ll r = N-i;
        if (!B[a-1].empty()) {
            auto iter = lower_bound(B[a-1].begin(), B[a-1].end(), i);
            if (iter != B[a-1].end()) {
                r = *iter - i;
            }
        }
        auto iter = lower_bound(B[a].begin(), B[a].end(), i+1);
        if (iter != B[a].end()) {
            r = min(r, *iter - i);
        }
        ans += l*r;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
