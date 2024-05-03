// https://atcoder.jp/contests/abc318/tasks/abc318_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> X(N), L(N), Y;
    for (int i = 0; i < N; i++) cin >> X[i];
    for (int i = 0; i < N; i++) cin >> L[i];
    for (ll x : X) {
        for (ll l : L) {
            Y.push_back(x-l-1);
            Y.push_back(x-l);
            Y.push_back(x+l+1);
            Y.push_back(x+l);
        }
    }
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    ll ans = 0;
    for (int i = 1; i < (int)Y.size(); i++) {
        ll y = Y[i];
        vector<ll> Z(N);
        for (ll j = 0; j < N; j++) Z[j] = abs(X[j] - y);
        sort(Z.begin(), Z.end());
        bool ok = true;
        for (int j = 0; j < N; j++) {
            if (Z[j] > L[j]) ok = false;
        }
        if (ok) ans += y - Y[i-1];
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
