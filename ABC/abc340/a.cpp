#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, d;
    cin >> a >> b >> d;
    for (int x = a; x != b; x += d) cout << x << " ";
    cout << b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
