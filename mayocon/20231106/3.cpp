// https://atcoder.jp/contests/abc195/tasks/abc195_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, w;
    cin >> a >> b >> w;
    w *= 1000;

    int mi = 1e+9, ma = -1;
    for (int k = 1; k < 1e+7; k++) {
        if (k*a <= w && w <= k*b) {
            mi = min(k, mi);
            ma = max(k, ma);
        } else if (w < k*a) {
            break;
        }
    }

    if (ma == -1) cout << "UNSATISFIABLE" << endl;
    else cout << mi << " " << ma << endl;
}
