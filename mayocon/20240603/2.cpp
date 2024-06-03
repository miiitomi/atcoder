// https://atcoder.jp/contests/abc120/tasks/abc120_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;

    string T;
    for (int i = 0; i < S.size(); i++) {
        if (T.empty()) {
            T.push_back(S[i]);
        } else if (T.back() == S[i]) {
            T.push_back(S[i]);
        } else {
            T.pop_back();
        }
    }

    cout << S.size() - T.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
