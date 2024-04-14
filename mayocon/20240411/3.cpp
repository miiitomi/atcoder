// https://atcoder.jp/contests/abc201/tasks/abc201_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    int ans = 0;
    for (int x = 0; x <= 9999; x++) {
        int y = x;
        vector<int> v(10, 0);
        for (int k = 0; k < 4; k++) {
            v[y % 10]++;
            y /= 10;
        }
        bool is_ok = true;
        for (int i = 0; i <= 9; i++) {
            if (S[i] == 'o' && v[i] == 0) is_ok = false;
            if (S[i] == 'x' && v[i] > 0) is_ok = false;
        }
        if (is_ok) ans++;
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
