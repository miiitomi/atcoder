#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S, T;
    cin >> S >> T;

    int tmp = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        if (tmp <= 2) {
            if ((int)(S[i] - 'a') == (int)(T[tmp] - 'A')) {
                tmp++;
            }
        }
    }

    if (tmp == 3 || (tmp == 2 && T.back() == 'X')) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
