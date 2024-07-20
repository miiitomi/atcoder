#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = unsigned long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;

    for (ll k = 1; k < 100; k++) {
        ll x = 1;
        for (ll i = 1; i <= (k+1)/2; i++) {
            if (i == 1) x *= 9;
            else x *= 10;
        }

        if (k == 1) x = 10;

        if (N > x) N -= x;
        else {
            string S(k, '.');
            ll y = 1;
            for (ll i = 1; i < (k+1)/2; i++) y*=10;
            y--;
            if (k == 1) y--;
            string n = to_string(N + y);
            for (ll i = 0; i <= min(k/2, (ll)n.size()-1); i++) {
                S[i] = n[i];
                S[k-1-i] = n[i];
            }
            cout << S << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
