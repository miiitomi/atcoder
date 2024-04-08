// https://atcoder.jp/contests/abc266/tasks/abc266_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool f(ll x1, ll y1, ll x2, ll y2) {
    return x1*y2 - y1*x2 >= 0;
}

void solve() {
    vector<ll> X(4), Y(4);
    for (int i = 0; i < 4; i++) cin >> X[i] >> Y[i];

    for (int i = 0; i < 4; i++) {
        if (!f(X[(i+1)%4] - X[i], Y[(i+1)%4] - Y[i], X[(i+3)%4] - X[i], Y[(i+3)%4] - Y[i])) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
