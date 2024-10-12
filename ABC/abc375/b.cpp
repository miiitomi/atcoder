#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

double d(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+0.0);
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    ll x = 0, y = 0;
    double ans = 0;
    for (int i = 0; i < N; i++) {
        ans += d(x, y, X[i], Y[i]);
        x = X[i];
        y = Y[i];
    }
    ans += d(x, y, 0, 0);
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
