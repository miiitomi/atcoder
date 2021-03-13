#include <bits/stdc++.h>
using namespace std;

bool x_is_greater_than_m(string X, int64_t n, int64_t M) {
    vector<int64_t> Y;
    while (M > 0) {
        int64_t a = M % n;
        M /= n;
        Y.push_back(a);
    }
    if (Y.size() > X.size()) {
        return false;
    } else if (X.size() > Y.size()) {
        return true;
    } else {
        int k = X.size();
        for (int i = 0; i < k; i++) {
            if ((int)(X.at(i) - '0') > Y.at(k - i - 1)) {
                return true;
            } else if ((int)(X.at(i) - '0') < Y.at(k - i - 1)) {
                return false;
            }
        }
        return false;
    }
}

int main() {
    string X;
    int64_t M;
    cin >> X >> M;

    if (X.size() == 1) {
        if (stoi(X) > M) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }

    int64_t d = 1LL;
    for (char x: X) {
        if ((int64_t)(x - '0') > d) {
            d = (int64_t)(x - '0');
        }
    }

    int64_t b = d;
    int64_t e = M + 1LL;

    while (e - b > 1) {
        int64_t h = (b + e) / 2;
        if (x_is_greater_than_m(X, h, M)) {
            e = h;
        } else {
            b = h;
        }
    }
    cout << b - d << endl;
}