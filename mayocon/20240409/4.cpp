// https://atcoder.jp/contests/abc152/tasks/abc152_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<vector<ll>> t(10, vector<ll>(10, 0));
    for (int x = 1; x <= N; x++) {
        int head, tail;
        tail = (x % 10);
        int y = x;
        while (y >= 10) y /= 10;
        head = y;
        t[head][tail]++;
    }

    ll ans = 0;
    for (int x = 1; x <= 9; x++) {
        for (int y = 1; y <= 9; y++) {
            ans += t[x][y] * t[y][x];
        }
    }
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
