#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    if (X > Y) swap(X, Y);
    if (X <= Z && Z <= Y) cout << "Yes\n";
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
