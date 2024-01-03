// https://atcoder.jp/contests/abc246/tasks/abc246_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> x(3), y(3);
    for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    if (x[0] == x[1]) cout << x[2] << " ";
    else cout << x[0] << " ";
    if (y[0] == y[1]) cout << y[2] << endl;
    else cout << y[0] << endl;
}
