// https://atcoder.jp/contests/abc142/tasks/abc142_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    if (N % 2 == 0) cout << "0.5" << endl;
    else if (N == 1) cout << "1.0" << endl;
    else cout << (N/2 + 1.0)/N << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
