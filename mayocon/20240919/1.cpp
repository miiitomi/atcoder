// https://atcoder.jp/contests/abc075/tasks/abc075_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<int> v(3);
    for (int &a : v) cin >> a;
    sort(v.begin(), v.end());
    if (v[0] == v[1]) cout << v[2] << endl;
    else cout << v[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
