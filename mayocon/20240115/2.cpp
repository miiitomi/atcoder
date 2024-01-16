// https://atcoder.jp/contests/abc104/tasks/abc104_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    if (S[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }

    int j = -1;
    for (int i = 2; i <= N-2; i++) {
        if (S[i] == 'C') {
            j = i;
            break;
        }
    }
    if (j == -1) {
        cout << "WA" << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (i == 0 || i == j) continue;
        char c = S[i];
        if ('a' <= c && c <= 'z') continue;
        else {
            cout << "WA" << endl;
            return 0;
        }
    }
    cout << "AC" << endl;
}
