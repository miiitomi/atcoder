// https://atcoder.jp/contests/abc351/tasks/abc351_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(vector<ll> X) {
    sort(X.begin(), X.end());
    ll N = X.size();
    vector<ll> S(N+1, 0);
    for (int i = 0; i < N; i++) S[i+1] = S[i] + X[i];
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += S[N] - S[i+1];
        ans -= (N-1-i)*X[i];
    }
    return ans/2;
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> X_odd, Y_odd, X_even, Y_even;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        if ((x+y) % 2 == 0) {
            X_even.push_back(x+y);
            Y_even.push_back(x-y);
        } else {
            X_odd.push_back(x+y);
            Y_odd.push_back(x-y);
        }
    }

    ll ans = f(X_odd) + f(X_even) + f(Y_odd) + f(Y_even);
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
