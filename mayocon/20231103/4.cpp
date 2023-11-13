// https://atcoder.jp/contests/abc076/tasks/abc076_c
#include <bits/stdc++.h>
using namespace std;

string S, T;
bool is_ok(int x) {
    if (x + (int)T.size() > (int)S.size()) return false;
    for (int i = 0; i < (int)T.size(); i++) {
        if (S[x+i] != '?' && S[x+i] != T[i]) return false;
    }
    return true;
}

int main() {
    cin >> S >> T;

    for (int i = (int)S.size()-1; i >= 0; i--) {
        if (is_ok(i)) {
            for (int j = 0; j < S.size(); j++) {
                if (S[j] == '?') {
                    if (j < i) S[j] = 'a';
                    else if (j - i < T.size()) S[j] = T[j - i];
                    else S[j] = 'a';
                }
            }
            cout << S << endl;
            return 0;
        }
    }

    cout << "UNRESTORABLE" << endl;
}
