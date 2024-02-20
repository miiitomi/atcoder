// https://atcoder.jp/contests/abc199/tasks/abc199_a
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a*a + b*b < c*c) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
