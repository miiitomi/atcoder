#include <bits/stdc++.h>
using namespace std;

void solve() {
    char c1, c2;
    int n1, n2;
    cin >> c1 >> n1 >> c2 >> n2;
    if (c1 == c2) {
        cout << abs(n1 - n2) << "\n";
    } else {
        cout << abs(n1+n2-1) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
