#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    ll T = 0;
    while (N--) {
        ll h;
        cin >> h;
        while (T%3 != 2 && h > 0) {
            T++;
            h--;
        }
        if (h == 0) continue;
        ll x = h/5;
        T += x*3;
        h -= x*5;
        while (h > 0) {
            T++;
            if (T%3 == 0) h -= 3;
            else h--;
        }
    }
    cout << T << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
