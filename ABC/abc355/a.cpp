#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == b) cout << -1 << endl;
    else if (a != 1 && b != 1) cout << 1 << endl;
    else if (a != 2 && b != 2) cout << 2 << endl;
    else if (a != 3 && b != 3) cout << 3 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
