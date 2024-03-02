#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, Q;
    string S;
    cin >> N >> S >> Q;

    string T = "abcdefghijklmnopqrstuvwxyz";
    while (Q--) {
        char c, d;
        cin >> c >> d;
        for (char &e : T) if (e == c) e = d;
    }

    for (char &c : S) {
        c = T[c-'a'];
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
