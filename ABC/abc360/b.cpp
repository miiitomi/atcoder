#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S, T;
    cin >> S >> T;

    for (int w = 1; w < (int)S.size(); w++) {
        for (int c = 1; c <= w; c++) {
            string s;
            for (int x = c-1; x <= S.size()-1; x += w) {
                s.push_back(S[x]);
            }
            if (s == T) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
