#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    string T;
    int state = 0;
    for (char c : S) {
        if (c == '|') state++;
        else if (state != 1) T.push_back(c);
    }
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
