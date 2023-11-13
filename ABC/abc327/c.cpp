#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A(9, vector<int>(9));

bool is_ok(int li, int ri, int lj, int rj) {
    vector<bool> c(9, false);
    for (int i = li; i <= ri; i++) {
        for (int j = lj; j <= rj; j++) {
            if (c[A[i][j]]) {
                return false;
            }
            c[A[i][j]] = true;
        }
    }
    return true;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    for (int li = 0; li < 9; li++) {
        if (!is_ok(li, li, 0, 8)) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int li = 0; li < 9; li++) {
        if (!is_ok(0, 8, li, li)) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int li = 0; li < 6; li += 3) {
        for (int lj = 0; lj <= 6; lj += 3) {
            if (!is_ok(li, li+2, lj, lj+2)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}
