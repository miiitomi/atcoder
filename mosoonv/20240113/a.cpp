// https://atcoder.jp/contests/abc213/tasks/abc213_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for (int c = 0; c <= 255; c++) {
        if ((a ^ c) == b) {
            cout << c << endl;
            return 0;
        }
    }
}
