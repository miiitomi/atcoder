#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int s = (int)S.size() - (int)T.size();
    while (s >= 0) {
        bool b = true;
        for (int i = 0; i < (int)T.size(); i++) {
            if (S[s+i] != '?' && S[s+i] != T[i]) {
                b = false;
                break;
            }
        }
        if (b) break;
        s--;
    }

    if (s < 0) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == '?') {
            if (i < s || s + (int)T.size() <= i) {
                S[i] = 'a';
            } else {
                S[i] = T[i - s];
            }
        }
    }

    cout << S << endl;
}
