// https://atcoder.jp/contests/abc283/tasks/abc283_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    int ans = 0;
    while (!S.empty()) {
        if (S.size() >= 2 && S[(int)S.size()-1] == '0' && S[(int)S.size()-2] == '0') {
            ans++;
            S.pop_back();
            S.pop_back();
        } else {
            ans++;
            S.pop_back();
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
