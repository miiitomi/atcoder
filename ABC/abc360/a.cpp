#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    int r, m;
    for (int i = 0; i < 3; i++) {
        if (S[i] == 'R') r = i;
        if (S[i] == 'M') m = i;
    }

    if (r < m) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
