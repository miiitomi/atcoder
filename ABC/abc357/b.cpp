#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    int lower = 0, upper = 0;
    for (char c : S) {
        if ('a' <= c && c <= 'z') lower++;
        else upper++;
    }

    if (upper > lower) {
        for (int i = 0; i < (int)S.size(); i++) {
            if ('a' <= S[i] && S[i] <= 'z') {
                S[i] = (S[i] - 'a') + 'A';
            }
        }
    } else {
        for (int i = 0; i < (int)S.size(); i++) {
            if ('A' <= S[i] && S[i] <= 'Z') {
                S[i] = (S[i] - 'A') + 'a';
            }
        }
    }

    cout << S << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
