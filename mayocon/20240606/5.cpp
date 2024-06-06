// https://atcoder.jp/contests/abc150/tasks/abc150_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M, X = 1;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] /= 2;
        X = lcm(X, A[i]);
        if (X > M) {
            cout << 0 << "\n";
            return;
        }
    }

    ll cnt;
    for (int i = 0; i < N; i++) {
        ll x = A[i], tmp = 0;
        while (x % 2 == 0) {
            tmp++;
            x /= 2;
        }
        if (i == 0) cnt = tmp;
        else if (cnt != tmp) {
            cout << 0 << "\n";
            return;
        }
    }

    ll r = 2e+9, l = 0;
    while (r - l > 1) {
        ll m = (l + r)/2;
        if (m*X > M) r = m;
        else l = m;
    }

    if (l % 2 == 1) l++;
    cout << l/2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
