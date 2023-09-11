// https://atcoder.jp/contests/abc259/tasks/abc259_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int i = 0, j = 0;
    while (true) {
        if (S[i] != T[j]) {
            cout << "No" << endl;
            return 0;
        }

        if (i < (int)S.size()-1 && j < (int)T.size() -1 && S[i] == S[i+1] && T[j] == T[j+1]) {
            int k=0, l=0;
            while (i + k < (int)S.size() && S[i] == S[i+k]) k++;
            while (j + l < (int)T.size() && T[j] == T[j+l]) l++;
            if (k <= l) {
                i += k;
                j += l;
            } else {
                cout << "No" << endl;
                return 0;
            }
        } else {
            i++;
            j++;
        }

        if (i == (int)S.size() && j == (int)T.size()) break;
        else if (i >= S.size() || j >= T.size()) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
