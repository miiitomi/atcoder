#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    bool ok = true;
    if (!('A' <= S[0] && S[0] <= 'Z')) ok = false;
    for (int i = 1; i < S.size(); i++) {
        if (!('a' <= S[i] && S[i] <= 'z')) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
