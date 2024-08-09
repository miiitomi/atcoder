// https://atcoder.jp/contests/abc350/tasks/abc350_a
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
    int x = 0;
    int k = 1;
    for (int i = 1; i <= 3; i++) {
        x += (s[s.size()-i]-'0')*k;
        k *= 10;
    }

    if (x != 316 && 1 <= x && x <= 349) cout << "Yes\n";
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
