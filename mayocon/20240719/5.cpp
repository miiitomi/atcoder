// https://atcoder.jp/contests/abc174/tasks/abc174_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, K;
vector<ll> A;

ll f(ll x) {
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        ll y = A[i];
        cnt += (y + x-1)/x - 1;
    }
    return cnt;
}

void solve() {
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll left = 0, right = 2e+9;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        ll cnt = f(m);
        if (cnt <= K) right = m;
        else left = m;
    }
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
