// https://atcoder.jp/contests/abc159/tasks/abc159_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    double L;
    cin >> L;
    L /= 3.0;
    cout << L*L*L << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
