// https://atcoder.jp/contests/abc300/tasks/abc300_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool is_prime(ll n) {
    for (ll x = 2; x*x <= n; x++) {
        if (n%x == 0) return false;
    }
    return true;
}

void solve() {
    ll N, P;
    cin >> N >> P;
    vector<ll> U = {1}, V = {1};
    for (ll x = 2; x <= P; x++) {
        if (!is_prime(x)) continue;
        if (U.size() > V.size()) swap(U, V);
        for (int i = 0; i < (int)U.size(); i++) {
            if (U[i] * x <= N) U.push_back(U[i]*x);
        }
    }
    sort(V.begin(), V.end());
    ll ans = 0;
    for (ll u : U) {
        ans += (ll)distance(V.begin(), lower_bound(V.begin(), V.end(), (N/u)+1));
    }
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
