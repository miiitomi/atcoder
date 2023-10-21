// https://atcoder.jp/contests/abc059/tasks/abc059_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    if (A.size() > B.size()) {
        cout << "GREATER" << endl;
    } else if (A.size() < B.size()) {
        cout << "LESS" << endl;
    } else if (A == B) {
        cout << "EQUAL" << endl;
    } else if (A < B) {
        cout << "LESS" << endl;
    } else {
        cout << "GREATER" << endl;
    }
}
