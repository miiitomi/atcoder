// https://atcoder.jp/contests/abc088/tasks/abc088_c
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c(3, vector<int>(3));

bool is_ok(int a0) {
    vector<int> a(3, a0), b(3, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 0) {
                b[j] = c[i][j] - a[i];
            } else if (j == 0) {
                a[i] = c[i][j] - b[j];
            } else {
                if (a[i] + b[j] != c[i][j]) return false;
            }
        }
    }
    return true;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> c[i][j];
    }

    for (int a0 = -1000; a0 <= 1000; a0++) {
        if (is_ok(a0)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
