// https://atcoder.jp/contests/abc076/tasks/abc076_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    ll x = 1;
    while (N--) {
        if (2*x < x+K) x = 2*x;
        else x = x+K;
    }
    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
