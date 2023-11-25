#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v(1e+7, 0);

int main() {
    for (ll x = 1; x < 1e+7; x++) v[x] = x*x;

    ll D;
    cin >> D;

    ll ans = (ll)1e+18;
    for (ll y = 1; y*y <= 2*D; y++) {
        ll T = D - (y*y);

        auto iter = lower_bound(v.begin(), v.end(), T);
        if (iter != v.begin()) iter--;
        ans = min(ans, abs(*iter - T));

        iter++;
        if (iter != v.end()) {
            ans = min(ans, abs(*iter - T));
        }
    }

    cout << ans << endl;
}
