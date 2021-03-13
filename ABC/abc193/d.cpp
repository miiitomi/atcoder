#include <bits/stdc++.h>
using namespace std;

int64_t point(string U, int x) {
    int64_t ans = 0;
    for (int i = 1; i <= 9; i++) {
        int counter = 0;
        for (char u: U) {
            if ((int)(u - '0') == i) {
                counter++;
            }
        }
        if (i == x) {
            counter++;
        }
        ans += i * pow(10LL, counter);
    }
    return ans;
}

int main() {
    int K;
    string S, T;
    cin >> K >> S >> T;

    vector<int64_t> A(10, 0);
    for (int i=1; i<=9; i++) {
        int counter = 0;
        for (char u: S) {
            if ((int)(u - '0') == i) {
                counter++;
            }
        }

        for (char u: T) {
            if ((int)(u - '0') == i) {
                counter++;
            }
        }
        A.at(i) = K-counter;
    }

    int64_t win_case = 0;
    for (int i=1; i<=9; i++) {
        for (int j = 0; j <= 9; j++) {
            if (point(S, i) > point(T, j)) {
                if (i != j) {
                    win_case += A.at(i) * A.at(j);
                } else {
                    win_case += A.at(i) * (A.at(i) - 1);
                }
            }
        }
    }
    double ans = (0.0 + win_case) / (0.0 + (9LL*K - 8) * (9LL*K-9));
    cout << ans << endl;
}