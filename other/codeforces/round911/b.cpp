#include <bits/stdc++.h>
using namespace std;

bool ok(int a, int b, int c) {
    if (b == c && b == 0) return a > 0;

    if (b < c) swap(b, c);

    if (c > 0) {
        return ok(a+1, b-1, c-1);
    }

    if (a == 0) return false;
    return ok(a-1, b-1, 1);
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (ok(a, b, c)) cout << 1 << " ";
    else cout << 0 << " ";
    if (ok(b, a, c)) cout << 1 << " ";
    else cout << 0 << " ";
    if (ok(c, a, b)) cout << 1 << "\n";
    else cout << 0 << "\n";
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
