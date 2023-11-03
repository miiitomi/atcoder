#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    int ans = abs(0 - y) + abs(y - x);

    int tmp = x;
    if (k < abs(x - y)) {
        tmp += k + 2*(abs(x-y) - k);
    } else {
        tmp += abs(x-y);
    }

    ans = min(ans, tmp);
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
