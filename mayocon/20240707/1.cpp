// https://atcoder.jp/contests/abc258/tasks/abc258_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int K;
    cin >> K;
    int h = 21, m = 0;
    h += K/60;
    m += K%60;
    cout << h << ":";
    if (m < 10) cout << "0" << m << endl;
    else cout << m << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
