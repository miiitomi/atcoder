#include <bits/stdc++.h>
using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz";

int main() {
    string S, T;
    cin >> S >> T;
    int K;
    if (S[0] < T[0]) {
        K = (T[0] - S[0]);
    } else {
        K = (int)('z' - S[0]) + (int)(T[0] - 'a') + 1;
    }

    for (int i = 0; i < (int)S.size(); i++) {
        if ((int)(S[i] - 'a') + K < 26) {
            S[i] = abc[(int)(S[i] - 'a') + K];
        } else {
            S[i] = abc[(int)(S[i] - 'a') + K - 26];
        }
    }
    if (S == T) cout << "Yes" << endl;
    else cout << "No" << endl;

}
