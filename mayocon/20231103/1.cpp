// https://atcoder.jp/contests/abc220/tasks/abc220_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    for (int x = a; x <= b; x++) {
        if (x % c == 0) {
            cout << x << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
