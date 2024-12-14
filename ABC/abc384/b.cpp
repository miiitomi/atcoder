#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, R;
    cin >> N >> R;
    while (N--) {
        ll d, a;
        cin >> d >> a;
        if (d == 1) {
            if (1600 <= R && R <= 2799) {
                R += a;
            }
        } else {
            if (1200 <= R && R <= 2399) {
                R += a;
            }
        }
    }
    cout << R << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
