// https://atcoder.jp/contests/abc169/tasks/abc169_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll A, B;
    double b;
    cin >> A >> b;
    B = round(100 * b);
    A *= B;
    A /= 100;
    cout << A << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
