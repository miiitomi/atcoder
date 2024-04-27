// https://atcoder.jp/contests/abc174/tasks/abc174_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;
vector<ll> A;

bool is_ok(ll x) {
    ll cnt = 0;
    for (ll a : A) {
        cnt += a/x;
        if (a % x == 0) cnt -= 1;
    }
    return cnt <= K;
}

void solve() {
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll left = 0, right = 1e+9;
    while (right - left > 1) {
        ll m = (right + left) / 2;
        if (is_ok(m)) right = m;
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
