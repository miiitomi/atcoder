// https://atcoder.jp/contests/abc235/tasks/abc235_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string s;
    cin >> s;
    int a = s[0]-'0', b = s[1]-'0', c = s[2]-'0';
    int ans = 111*(a+b+c);
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
