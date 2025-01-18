#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll X;
    cin >> X;
    ll tmp = 1;
    for (ll n = 1; true; n++) {
        tmp *= n;
        if (tmp == X) {
            cout << n << "\n";
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
