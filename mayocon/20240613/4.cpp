// https://atcoder.jp/contests/abc235/tasks/abc235_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x) {
    if (x < 10 || x%10 == 0) return (ll)1e+9;
    ll y = x % 10;
    x /= 10;
    ll k = 1;
    while (k <= x) k *= 10;
    x += k*y;
    return x;
}

void solve() {
    ll a, N;
    cin >> a >> N;
    vector<ll> d(1e+6, -1);
    d[1] = 0;
    queue<ll> Q;
    Q.push(1);
    while (!Q.empty()) {
        ll x = Q.front();
        Q.pop();
        ll y = a * x;
        if (1 <= y && y < 1e+6 && d[y] == -1) {
            d[y] = d[x] + 1;
            Q.push(y);
        }
        y = f(x);
        if (1 <= y && y < 1e+6 && d[y] == -1) {
            d[y] = d[x] + 1;
            Q.push(y);
        }
    }
    cout << d[N] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
