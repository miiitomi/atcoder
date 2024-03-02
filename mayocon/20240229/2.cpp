// https://atcoder.jp/contests/abc196/tasks/abc196_c;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    ll cnt = 0;
    for (ll x = 1; x < N; x++) {
        ll y = x;
        ll b = 1;
        while (b <= x) b *= 10;
        y += b * x;
        if (y > N) break;
        else cnt++;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
