// https://atcoder.jp/contests/typical90/tasks/typical90_ag
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W;
    cin >> H >> W;
    if (H == 1 || W == 1) cout << max(H, W) << "\n";
    else cout << ((H+1)/2) * ((W+1)/2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
