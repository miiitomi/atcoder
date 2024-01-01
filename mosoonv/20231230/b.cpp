// https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    if (S.size() < 3) {
        cout << "No" << endl;
    } else {
        while (S.size() > 4) S.pop_back();
        if (S == "YAKI") {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
