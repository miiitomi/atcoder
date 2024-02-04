#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    string T;
    while (S.back() != '.') {
        T.push_back(S.back());
        S.pop_back();
    }
    reverse(T.begin(), T.end());
    cout << T << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
