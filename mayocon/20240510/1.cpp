// https://atcoder.jp/contests/abc143/tasks/abc143_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string T;
    while (N--) {
        char c;
        cin >> c;
        if (T.empty() || T.back() != c) T.push_back(c);
    }
    cout << T.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
