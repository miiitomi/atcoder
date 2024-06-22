// https://atcoder.jp/contests/abc079/tasks/abc079_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v(4);
    for (int k = 0; k < 4; k++) {
        char c;
        cin >> c;
        v[k] = c-'0';
    }

    for (int s = 0; s < (1 << 3); s++) {
        int tmp = v[0];
        for (int i = 0; i < 3; i++) {
            if (s & (1 << i)) tmp += v[i+1];
            else tmp -= v[i+1];
        }

        if (tmp == 7) {
            cout << v[0];
            for (int i = 0; i < 3; i++) {
                if (s & (1 << i)) cout << "+" << v[i+1];
                else cout << "-" << v[i+1];
            }
            cout << "=7\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
