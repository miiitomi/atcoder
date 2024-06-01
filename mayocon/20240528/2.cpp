// https://atcoder.jp/contests/abc139/tasks/abc139_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll n) {
    return (n+1)*n/2;
}

void solve() {
    ll N;
    cin >> N;
    cout << f(N-1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
