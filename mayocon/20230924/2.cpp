// https://atcoder.jp/contests/abc100/tasks/abc100_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, N;
    cin >> D >> N;

    if (N <= 99) {
        int x = N;
        for (int i = 0; i < D; i++) x *= 100;
        cout << x << endl;
    } else {
        if (D == 0) cout << 101 << endl;
        else if (D == 1) cout << 10100 << endl;
        else cout << 1010000 << endl;
    }
}
