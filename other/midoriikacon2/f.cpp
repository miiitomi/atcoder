#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll M;
    cin >> M;
    vector<ll> d(10, 0);
    for (int i = 1; i <= 9; i++) cin >> d[i];
    ll s = 0;
    for (int i = 1; i <= 9; i++) {
        for (int k = 0; k < d[i]; k++) {
            s = s*10 + i;
        }
    }
    s *= (ll)1e+9;

    if (s % M == 0) cout << s << endl;
    else {
        ll a = M - (s % M);
        s += a;
        cout << s << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
