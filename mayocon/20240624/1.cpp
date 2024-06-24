// https://atcoder.jp/contests/abc324/tasks/abc324_b
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

void solve() {
    ll N;
    cin >> N;

    for (ll x = 0; x < 100; x++) {
        ll tmp = 1;
        for (ll k = 0; k <x; k++) tmp *= 2;
        if (tmp > N) break;
        for (ll y = 0; y < 100; y++) {
            ll tmp2 = tmp;
            for (ll j = 0; j < y; j++) tmp2 *= 3;
            if (tmp2 > N) break;
            if (tmp2 == N) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
