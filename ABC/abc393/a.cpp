#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string s, t;
    cin >> s >> t;
    int ans;
    if (s == "sick" && t == "sick") ans = 1;
    else if (s == "sick") ans = 2;
    else if (t == "sick") ans = 3;
    else ans = 4;
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
