#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k, H;
    cin >> n >> m >> k >> H;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        int x = abs(H - h);

        if (x % k == 0 && x / k >= 1 && x / k <= m-1) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
