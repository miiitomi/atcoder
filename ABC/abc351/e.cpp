#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(vector<ll> X) {
    sort(X.begin(), X.end());
    int M = X.size();
    for (int i = M-1; i >= 0; i--) X[i] -= X[0];
    ll ans = 0, tmp = 0;
    for (int i = 0; i < M; i++) {
        ans += (i * X[i] - tmp);
        tmp += X[i];
    }
    return ans;
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> X1, Y1, X2, Y2;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        if ((x+y) % 2 == 0) {
            ll a = (x + y) / 2, b = (-x + y) / 2;
            X1.push_back(a);
            Y1.push_back(b);
        } else {
            y++;
            ll a = (x + y) / 2, b = (-x + y) / 2;
            X2.push_back(a);
            Y2.push_back(b);
        }
    }
    ll ans = 0;
    ans += f(X1);
    ans += f(X2);
    ans += f(Y1);
    ans += f(Y2);
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
