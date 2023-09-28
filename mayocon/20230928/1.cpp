// https://atcoder.jp/contests/abc270/tasks/abc270_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    if (X*Y < 0 || abs(X) < abs(Y)) {
        cout << abs(X) << endl;
        return 0;
    }

    if (Y*Z < 0 || abs(Z) < abs(Y)) {
        cout << abs(Z) + abs(Z - Y) + abs(Y - X) << endl;
        return 0;
    }

    cout << -1 << endl;
}
