// https://atcoder.jp/contests/abc158/tasks/abc158_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    for (int x = 1; x <= 1e+5; x++) {
        int s = (x * 8) / 100, t = (x * 10) / 100;
        if (s == a && t == b) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
