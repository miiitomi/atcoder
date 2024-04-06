#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    set<string> T;
    for (int l = 0; l < (int)S.size(); l++) {
        for (int r = l; r < (int)S.size(); r++) {
            string s;
            for (int k = l; k <= r; k++) s.push_back(S[k]);
            T.insert(s);
        }
    }

    cout << T.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
