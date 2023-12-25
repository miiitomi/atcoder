#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> x(Q), y(Q), z(Q), w(Q);
    for (int i = 0; i < Q; i++) {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
        x[i]--;
        y[i]--;
        z[i]--;
    }

    ll ans = 1;
    for (ll k = 0; k < 60; k++) {
        ll tmp = 0;
        for (ll s = 0; s < (1 << N); s++) {
            bool ok = true;
            for (int q = 0; q < Q; q++) {
                bool a = (s & (1 << x[q])), b = (s & (1 << y[q])), c = (s & (1 << z[q]));
                bool r = (w[q] & (1LL << k));
                if ((a||b||c) != r) {
                    ok = false;
                    break;
                }
            }
            if (ok) tmp++;
        }
        ans = ans * tmp % MOD;
    }

    cout << ans << endl;
}
