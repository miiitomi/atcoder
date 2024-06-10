// https://atcoder.jp/contests/abc173/tasks/abc173_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    int x = 0;
    while (x < N) x += 1000;
    cout << x - N << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
