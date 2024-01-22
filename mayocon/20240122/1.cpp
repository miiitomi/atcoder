// https://atcoder.jp/contests/abc077/tasks/abc077_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    ll x = 1;

    while ((x+1)*(x+1) <= N) x++;
    cout << x * x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
