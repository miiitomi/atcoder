#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    if (tx < sx) {
        swap(sx, tx);
        swap(sy, ty);
    }
    if ((sx+sy)%2 == 0) {
        sx++;
    }
    ll ans = abs(ty - sy);
    sy = ty;
    sx += min(ans, (tx - sx));
    if ((sx+sy)%2 == 0 || (sx%2 == tx%2)) ans += (tx-sx)/2;
    else ans += (tx-sx+1)/2;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
