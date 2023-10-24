// https://atcoder.jp/contests/abc182/tasks/abc182_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = 0;
    for (char c : S) N += (int)(c - '0');

    if (N % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (S.size() == 1) {
        cout << -1 << endl;
        return 0;
    }

    for (char c : S) {
        if ((N - (int)(c-'0'))% 3 == 0) {
            cout << 1 << endl;
            return 0;
        }
    }

    if (S.size() == 2) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < (int)S.size()-1; i++) {
        for (int j = i+1; j < (int)S.size(); j++) {
            if ((N - (int)(S[i]-'0') - (int)(S[j] - '0')) % 3 == 0) {
                cout << 2 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
