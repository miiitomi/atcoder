// https://atcoder.jp/contests/abc189/tasks/abc189_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, X;
    cin >> N >> X;
    X *= 100;
    ll tmp = 0;
    for (int i = 0; i < N; i++) {
        ll v, p;
        cin >> v >> p;
        tmp += v*p;
        if (tmp > X) {
            cout << i+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
