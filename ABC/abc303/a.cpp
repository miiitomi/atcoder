#include <bits/stdc++.h>
using namespace std;

bool same_char(char x, char y) {
    if (x == y) return true;
    if ((x == '1' && y == 'l') || (x == 'l' && y == '1')) return true;
    if ((x == '0' && y == 'o') || (x == 'o' && y == '0')) return true;
    return false;
}

int main() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    for (int i = 0; i < N; i++) {
        if (!same_char(S[i], T[i])) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
