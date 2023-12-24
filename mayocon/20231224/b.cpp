// https://atcoder.jp/contests/abc059/tasks/abc059_b
#include <bits/stdc++.h>
using namespace std;

bool is_small(string &A, string &B) {
    if (A.size() != B.size()) return A.size() < B.size();
    return A < B;
}

int main() {
    string a, b;
    cin >> a >> b;

    if (is_small(a, b)) {
        cout << "LESS" << endl;
    } else if (is_small(b, a)) {
        cout << "GREATER" << endl;
    } else {
        cout << "EQUAL" << endl;
    }
}
