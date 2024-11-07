// https://atcoder.jp/contests/abc133/tasks/abc133_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int L, R;
    cin >> L >> R;
    vector<bool> is_in(2019, false);
    for (int x = L; x <= min(R, L+2019); x++) {
        is_in[x%2019] = true;
    }
    int ans = 3000;
    for (int i = 0; i < 2019; i++) {
        for (int j = i+1; j < 2019; j++) {
            if (!(is_in[i] && is_in[j])) continue;
            ans = min(ans, (i*j)%2019);
        }
    }
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
