// https://atcoder.jp/contests/abc165/tasks/abc165_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll x = min(n, b-1);
    cout << (a*x)/b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
