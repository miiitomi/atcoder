// https://atcoder.jp/contests/abc144/tasks/abc144_e
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
    vector<ll> A(N), F(N);
    for (ll &a : A) cin >> a;
    for (ll &f : F) cin >> f;
    sort(A.begin(), A.end());
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());

    ll left = -1, right = INF;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        ll tmp = 0;
        for (int i = 0; i < N; i++) {
            ll a = m/F[i];
            tmp += max(0LL, A[i]-a);
        }
        if (tmp <= K) right = m;
        else left = m;
    }
    cout << right << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
