// https://atcoder.jp/contests/abc143/tasks/abc143_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    while (N--) {
        char c;
        cin >> c;
        if (S.empty() || S.back() != c) S.push_back(c);
    }
    cout << S.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
