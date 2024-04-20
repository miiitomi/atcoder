// https://atcoder.jp/contests/abc297/tasks/abc297_g
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

void solve() {
    ll N, L, R;
    cin >> N >> L >> R;
    ll tmp = 0;
    while (N--) {
        ll a;
        cin >> a;
        a %= R+L;
        tmp ^= (a / L);
    }
    if (tmp > 0) cout << "First\n";
    else cout << "Second\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
