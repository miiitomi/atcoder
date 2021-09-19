#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll __pow(ll b, ll c) {
    ll ans = 1LL;
    for (ll i = 0; i < b; i++) {
        ans *= c;
    }
    return ans;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll c_b = __pow(b, c);
    if (a < c_b) cout << "Yes" << endl;
    else cout << "No" << endl;
}
