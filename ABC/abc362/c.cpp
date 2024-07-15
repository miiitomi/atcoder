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
    vector<ll> L(N), R(N), X(N, 0);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        X[i] = L[i];
        sum += L[i];
    }

    for (int i = 0; i < N; i++) {
        ll r = max(0LL, 0-sum);
        ll d = min(R[i]-L[i], r);
        X[i] += d;
        sum += d;
    }

    if (sum != 0) cout << "No\n";
    else {
        cout << "Yes\n";
        for (ll x : X) cout << x << " ";
        cout << endl;
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
