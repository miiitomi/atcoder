#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a = 0, b = 0;
    for (int i = 0; i < 9; i++) {
        int x;
        cin >> x;
        a += x;
    }
    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        b += x;
    }
    int ans = max((a - b) + 1, 0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
