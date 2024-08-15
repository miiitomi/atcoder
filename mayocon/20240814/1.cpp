// https://atcoder.jp/contests/abc219/tasks/abc219_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<string> s(3);
    for (int i = 0; i < 3; i++) cin >> s[i];
    string ans;
    string T;
    cin >> T;
    for (char t : T) {
        ans = ans + s[t-'1'];
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
