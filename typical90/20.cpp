// https://atcoder.jp/contests/typical90/tasks/typical90_t
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    __int128_t X = a, Y = 1;
    for (int k = 0; k < b && Y <= X; k++) Y *= c;
    if (X < Y) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
