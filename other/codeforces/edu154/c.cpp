#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    int N = (int)S.size();
    int tmp_nums = 0;
    int last_true_num = 0;
    int last_false_num = 1e+9;
    bool must_true = true;
    bool maybe = true;

    for (int i = 0; i < N; i++) {
        char c = S[i];
        if (c == '+') {
            tmp_nums++;
            if (tmp_nums >= 2) must_true = false;
        }
        if (c == '-') {
            if (tmp_nums <= 0) {
                cout << "NO" << endl;
                return;
            } else {
                tmp_nums--;
                if (tmp_nums <= 1 || tmp_nums <= last_true_num) {
                    must_true = true;
                    maybe = true;
                    last_true_num = tmp_nums;
                    last_false_num = 1e+9;
                } else if (tmp_nums < last_false_num) {
                    maybe = true;
                    last_false_num = 1e+9;
                }
            }
        }
        if (c == '1') {
            if (!maybe) {
                cout << "NO" << endl;
                return;
            } else {
                last_true_num = max(last_true_num, tmp_nums);
                must_true = true;
                maybe = true;
                last_false_num = 1e+9;
            }
        }
        if (c == '0') {
            if (must_true) {
                cout << "NO" << endl;
                return;
            } else {
                must_true = false;
                maybe = false;
                last_false_num = min(last_false_num, tmp_nums);
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}