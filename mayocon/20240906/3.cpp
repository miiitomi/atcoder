// https://atcoder.jp/contests/abc205/tasks/abc205_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    while (Q--) {
        ll K;
        cin >> K;
        ll left = 0, right = INF;
        while (right - left > 1) {
            ll m = (left + right) / 2;
            auto iter = lower_bound(A.begin(), A.end(), m+1);
            ll k = m - (ll)distance(A.begin(), iter);
            if (k >= K) right = m;
            else left = m;
        }
        cout << right << "\n";
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
