#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;
    ll ans = 1;
    for (int i = 0; i < (int)S.size()-1; i++) {
        ll tmp = S[i] - S[i+1];
        if (tmp < 0) tmp += 10;
        ans += tmp + 1;
    }
    ans += (S.back() - '0');
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
