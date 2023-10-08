#include <bits/stdc++.h>
using namespace std;

bool is_ok(string &S, int x) {
    for (int i = 0; true; i++) {
        if (i == x && i + x == (int)S.size()) return false;
        if (i == x) return true;
        if (i + x == (int)S.size()) return false;
        if (S[i] > S[x+i]) return false;
        if (S[i] < S[x+i]) return true;
    }
}

void solve() {
    int N;
    string S;
    cin >> N >> S;

    for (int i = 1; i < N; i++) {
        if (is_ok(S, i)) {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
