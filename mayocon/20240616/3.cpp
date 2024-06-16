// https://atcoder.jp/contests/abc201/tasks/abc201_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;

    vector<int> v(4, 0);
    int ans = 0;
    for (v[0] = 0; v[0] <= 9; v[0]++) {
        for (v[1] = 0; v[1] <= 9; v[1]++) {
            for (v[2] = 0; v[2] <= 9; v[2]++) {
                for (v[3] = 0; v[3] <= 9; v[3]++) {
                    bool is_ok = true;
                    for (int x = 0; x <= 9; x++) {
                        if (S[x] == 'o') {
                            if (v[0] != x && v[1] != x && v[2] != x && v[3] != x) is_ok = false;
                        } else if (S[x] == 'x') {
                            if (v[0] == x || v[1] == x || v[2] == x || v[3] == x) is_ok = false;
                        }
                    }
                    if (is_ok) ans++;
                }
            }
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
