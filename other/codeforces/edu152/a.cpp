#include <bits/stdc++.h>
using namespace std;

void solve() {
    int b, c, h;
    cin >> b >> c >> h;
    cout << 2 * min(b-1, c+h) + 1 << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
