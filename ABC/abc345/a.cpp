#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    if (S[0] != '<' || S.back() != '>') {
        cout << "No\n";
        return;
    }
    for (int i = 1; i + 1 < (int)S.size(); i++) {
        if (S[i] != '=') {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
