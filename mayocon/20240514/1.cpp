// https://atcoder.jp/contests/abc344/tasks/abc344_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v;
    while (true) {
        int a;
        cin >> a;
        v.push_back(a);
        if (a == 0) break;
    }

    reverse(v.begin(), v.end());
    for (int a : v) cout << a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
