// https://atcoder.jp/contests/abc293/tasks/abc293_f
#include <bits/stdc++.h>
using namespace std;
typedef __int128_t ll;

ll _pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = _pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    else return res * res;
}

void solve() {
    long long _N;
    cin >> _N;
    ll N = _N;

    if (N == 2) {
        cout << 1 << endl;
        return;
    }

    ll D = 1;
    while (_pow(2, D) <= N) D++;
    ll ans = 2;

    for (ll d = 3; d <= D; d++) {
        ll left = 1;
        ll right = _pow(2, 61/(d-1) + 1);
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (_pow(mid, d-1) <= N) {
                left = mid;
            } else {
                right = mid;
            }
        }
        ll b = left;

        if (N >= _pow(b, d)) continue;

        bool is_ok = true;
        for (ll k = 1; k <= d; k++) {
            ll x = (N % _pow(b, k)) / _pow(b, k-1);
            if (x == 0 || x == 1) continue;
            else {
                is_ok = false;
                break;;
            }
        }

        if (is_ok) ans++;
    }

    cout << (long long)ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
