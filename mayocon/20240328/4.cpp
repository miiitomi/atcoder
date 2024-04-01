// https://atcoder.jp/contests/abc233/tasks/abc233_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string X;
    cin >> X;
    reverse(X.begin(), X.end());
    int s = 0, c = 0;
    for (char x : X) s += (x - '0');
    string ans;
    int N = X.size();
    for (int i = 0; (i < N) || (c > 0); i++) {
        if (s > 0) c += s;
        ans.push_back('0' + c % 10);
        c /= 10;
        if (i < N) s -= X[i] - '0';
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
