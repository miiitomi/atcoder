#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll v, x, fo, fi, q, r;
    cin >> v >> x >> fo >> fi >> q >> r;

    ll tmp = x + (fi - fo) * r;
    if (tmp <= 0) {
        cout << "Zero\n";
        return;
    } else if (tmp > v) {
        cout << "Overflow\n";
        return;
    }

    tmp = fi*r - fo*q;
    if (tmp < 0) cout << "Zero\n";
    else if (tmp > 0) cout << "Overflow\n";
    else cout << "Safe\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
