// https://atcoder.jp/contests/abc236/tasks/abc236_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    int a, b;
    cin >> a >> b;
    swap(S[a-1], S[b-1]);
    cout << S << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
