// https://atcoder.jp/contests/abc192/tasks/abc192_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e+18;

string X;
ll M, K;
ll f;

bool is_ok(ll y) {
    if (y == (ll)1e+18 - 1) {
        ll a = 0;
    }
    vector<ll> p(K, 1);
    for (int i = 1; i < K; i++) {
        ll x = p[i-1];
        if (INF / (x * f) < y) return false;
        p[i] = x * y;
    }
    ll a = 0;
    for (int i = K-1; i >= 0; i--) {
        a += p[i] * (ll)(X[K-1-i] - '0');
        if (a > M) return false;
    }
    return true;
}

int main() {
    cin >> X >> M;
    K = X.size();

    f = (ll)(X[0] - '0');

    if (K == 1) {
        ll x = f;
        if (x <= M) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    ll d = -1;
    for (char x : X) d = max(d, (ll)(x - '0'));

    if (!is_ok(d + 1)) {
        cout << 0 << endl;
        return 0;
    }

    ll left = d+1;
    ll right = (ll)(1e+18) + 10;

    while (right - left > 1) {
        ll mid = (left + right) / 2LL;
        if (is_ok(mid)) left = mid;
        else right = mid;
    }

    cout << left - d << endl;
}
