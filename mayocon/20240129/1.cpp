// https://atcoder.jp/contests/abc167/tasks/abc167_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S, T;
    cin >> S >> T;
    for (char c = 'a'; c <= 'z'; c++) {
        if (S + c == T) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
