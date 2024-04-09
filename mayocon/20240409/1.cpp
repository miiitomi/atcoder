// https://atcoder.jp/contests/abc338/tasks/abc338_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    for (int i = 0; i < (int)S.size(); i++) {
        if (i == 0) {
            if (!('A' <= S[i] && S[i] <= 'Z')) {
                cout << "No\n";
                return;
            }
        } else {
            if (!('a' <= S[i] && S[i] <= 'z')) {
                cout << "No\n";
                return;
            }
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
