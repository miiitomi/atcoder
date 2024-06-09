#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, L, R;
    cin >> N >> L >> R;
    R++;
    ll ans = 0;

    for (ll l = L; l < R; ) {
        ll i = 0;
        while (true) {
            if (l % (1LL << i) != 0) {
                i--;
                break;
            }
            ll j = l / (1LL << i);
            ll r = (1LL << i) * (j+1);
            if (r > R) {
                i--;
                break;
            }
            i++;
        }

        ll j = l / (1LL << i);
        ll r = (1LL << i) * (j + 1);

        ll res;
        cout << "? " << i << " " << j << endl;
        cin >> res;
        ans = (ans + res) % 100;
        l = r;
    }

    cout << "! " << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
