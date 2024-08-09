// https://atcoder.jp/contests/abc305/tasks/abc305_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> A;
vector<ll> S;

ll f(ll t) {
    auto iter = lower_bound(A.begin(), A.end(), t+1);
    if (iter == A.begin()) return 0;
    iter--;
    ll i = distance(A.begin(), iter);
    ll ans = S[i];
    if (i%2 == 1) ans += t-A[i];
    return ans;
}

void solve() {
    cin >> N;
    A.resize(N);
    S.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i > 0) {
            S[i] = S[i-1];
            if (i % 2 == 0) S[i] += A[i]-A[i-1];
        }
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        ll l, r;
        cin >> l >> r;
        cout << f(r)-f(l) << "\n";
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
