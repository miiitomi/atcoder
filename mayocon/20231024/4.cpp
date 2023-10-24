// https://atcoder.jp/contests/abc234/tasks/abc234_e
#include <bits/stdc++.h>
using namespace std;

bool f(string X, string &Y) {
    Y = X;
    int s = -9;

    while (Y[0] + s <= '9') {
        bool ok = true;
        for (int j = 1; j < (int)Y.size(); j++) {
            if (Y[j-1] + s > '9' || Y[j-1] + s < '0') {
                ok = false;
                break;
            }
            Y[j] = Y[j-1] + s;
        }
        if (ok && Y >= X) return true;
        s++;
    }
    return false;
}

int main() {
    string X;
    cin >> X;

    if (X.size() <= 2) {
        cout << X << endl;
        return 0;
    }

    string Y;
    if (f(X, Y)) {
        cout << Y << endl;
        return 0;
    }

    for (int i = 1; i < (int)X.size(); i++) X[i] = '0';
    if (X[0] == '9') {
        X[0] = '1';
        X.push_back('0');
    } else {
        X[0] = X[0] + 1;
    }

    f(X, Y);
    cout << Y << endl;
}
