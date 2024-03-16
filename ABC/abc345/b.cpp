#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll X;
    cin >> X;

    if (X >= 0) {
        X = (X + 9) / 10;
        cout << X << endl;
    } else {
        X = -(abs(X)/10);
        cout << X << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
