#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S, T;
    cin >> S >> T;
    if (S == "AtCoder" && T == "Land") cout << "Yes\n";
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
