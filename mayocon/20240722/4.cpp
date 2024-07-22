// https://atcoder.jp/contests/abc161/tasks/abc161_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<ll> S;
void rec(ll x, ll k) {
    if (k == 0) {
        S.push_back(x);
        return;
    }

    ll a = x%10;
    for (ll b = max(a-1, 0LL); b <= min(a+1, 9LL); b++) {
        ll y = 10*x + b;
        rec(y, k-1);
    }
}

void solve() {
    ll K;
    cin >> K;

    for (ll k = 1; (k <= 18 && (ll)S.size() < K); k++) {
        for (ll x = 1; (x <= 9 && (ll)S.size() < K); x++) {
            rec(x, k-1);
        }
    }

    sort(S.begin(), S.end());
    cout << S[K-1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
